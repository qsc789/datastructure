#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// 邻接矩阵
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

// 邻接链表
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    struct Node* adjList[MAX_VERTICES];
};

void addEdgeMatrix(int v1, int v2) {
    adjacencyMatrix[v1][v2] = 1;
    adjacencyMatrix[v2][v1] = 1;
}

void displayAdjacencyMatrix(int numVertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdgeList(struct Graph* graph, int v1, int v2) {
    struct Node* newNode = createNode(v2);
    newNode->next = graph->adjList[v1];
    graph->adjList[v1] = newNode;

    newNode = createNode(v1);
    newNode->next = graph->adjList[v2];
    graph->adjList[v2] = newNode;
}

void displayAdjacencyList(struct Graph* graph, int numVertices) {
    printf("Adjacency List:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d -> ", i);
        struct Node* current = graph->adjList[i];
        while (current) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 4;
    struct Graph graph;
    for (int i = 0; i < numVertices; i++) {
        graph.adjList[i] = NULL;
    }

    addEdgeMatrix(0, 1);
    addEdgeMatrix(0, 2);
    addEdgeMatrix(1, 3);
    addEdgeMatrix(2, 3);

    displayAdjacencyMatrix(numVertices);

    addEdgeList(&graph, 0, 1);
    addEdgeList(&graph, 0, 2);
    addEdgeList(&graph, 1, 3);
    addEdgeList(&graph, 2, 3);

    displayAdjacencyList(&graph, numVertices);

    return 0;
}
