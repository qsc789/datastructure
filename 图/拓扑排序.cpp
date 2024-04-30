#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6

// 邻接链表的节点结构体
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 邻接链表数组
Node* adjacencyList[MAX_VERTICES];

// 入度数组
int inDegree[MAX_VERTICES];

// 初始化邻接链表和入度数组
void initGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjacencyList[i] = NULL;
        inDegree[i] = 0;
    }

    // 添加边到邻接链表
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);
}

// 添加边到邻接链表
void addEdge(int v1, int v2) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v2;
    newNode->next = adjacencyList[v1];
    adjacencyList[v1] = newNode;
    inDegree[v2]++;
}

// 拓扑排序算法
void topologicalSort() {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    int sortedVertices[MAX_VERTICES];
    int sortedIndex = 0;

    // 将入度为0的顶点入队
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front != rear) {
        int vertex = queue[front++];
        sortedVertices[sortedIndex++] = vertex;

        // 遍历该顶点的邻接节点，更新入度
        Node* current = adjacencyList[vertex];
        while (current != NULL) {
            int nextVertex = current->vertex;
            inDegree[nextVertex]--;
            if (inDegree[nextVertex] == 0) {
                queue[rear++] = nextVertex;
            }
            current = current->next;
        }
    }

    // 打印拓扑排序结果
    printf("Topological Sort: ");
    for (int i = 0; i < sortedIndex; i++) {
        printf("%d ", sortedVertices[i]);
    }
    printf("\n");
}

int main() {
    initGraph();
    
    // 执行拓扑排序
    topologicalSort();

    return 0;
}
