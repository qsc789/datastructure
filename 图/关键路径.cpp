#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 最大顶点数量
#define MAX_VERTICES 10
// 无限大值，表示不可达
#define INF INT_MAX

typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    Edge* adjList[MAX_VERTICES];
    int inDegree[MAX_VERTICES];
    int numVertices;
} Graph;

// 创建图
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // 初始化邻接表和入度数组
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->inDegree[i] = 0;
    }

    return graph;
}

// 添加有向边
void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = graph->adjList[src];
    graph->adjList[src] = newEdge;

    // 更新目标顶点的入度
    graph->inDegree[dest]++;
}

// 拓扑排序
void topologicalSort(Graph* graph, int* topOrder) {
    int visited[MAX_VERTICES];
    int stack[MAX_VERTICES];
    int top = -1;
    int index = 0;

    // 初始化visited数组
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    // 将入度为0的顶点入栈
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->inDegree[i] == 0) {
            stack[++top] = i;
        }
    }

    while (top != -1) {
        int vertex = stack[top--];
        topOrder[index++] = vertex;

        Edge* temp = graph->adjList[vertex];
        while (temp) {
            graph->inDegree[temp->dest]--;
            if (graph->inDegree[temp->dest] == 0) {
                stack[++top] = temp->dest;
            }
            temp = temp->next;
        }
    }
}

// 求解关键路径
void criticalPath(Graph* graph, int startVertex) {
    int topOrder[MAX_VERTICES];
    topologicalSort(graph, topOrder);

    int ee[MAX_VERTICES] = {0};  // 事件最早开始时间
    int le[MAX_VERTICES];        // 事件最迟开始时间
    for (int i = 0; i < graph->numVertices; i++) {
        le[i] = INF;
    }

    // 计算事件最早开始时间
    for (int i = 0; i < graph->numVertices; i++) {
        int vertex = topOrder[i];
        Edge* temp = graph->adjList[vertex];
        while (temp) {
            int dest = temp->dest;
            if (ee[dest] < ee[vertex] + temp->weight) {
                ee[dest] = ee[vertex] + temp->weight;
            }
            temp = temp->next;
        }
    }

    // 计算事件最迟开始时间
    le[startVertex] = ee[graph->numVertices - 1];  // 设置终点的最迟开始时间为关键路径长度
    for (int i = graph->numVertices - 1; i >= 0; i--) {
        int vertex = topOrder[i];
        Edge* temp = graph->adjList[vertex];
        while (temp) {
            int dest = temp->dest;
            if (le[vertex] > le[dest] - temp->weight) {
                le[vertex] = le[dest] - temp->weight;
            }
            temp = temp->next;
        }
    }

    // 输出关键路径
    printf("Critical Path:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* temp = graph->adjList[i];
        while (temp) {
            int dest = temp->dest;
            int eTime = ee[i];
            int lTime = le[dest] - temp->weight;
            printf("(%d -> %d) Weight: %d, Slack: %d\n", i, dest, temp->weight, lTime - eTime);
            temp = temp->next;
        }
    }
}

int main() {
    Graph* graph = createGraph(6);

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 3, 5, 5);
    addEdge(graph, 4, 5, 3);

    criticalPath(graph, 0);

    return 0;
}
