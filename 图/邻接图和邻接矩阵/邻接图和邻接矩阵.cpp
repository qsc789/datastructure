#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

// 邻接矩阵
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

// 邻接链表的节点结构体
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 邻接链表数组
Node* adjacencyList[MAX_VERTICES];

// 逆邻接链表数组
Node* inverseAdjacencyList[MAX_VERTICES];

// 初始化图的邻接矩阵
void initAdjacencyMatrix() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[0][3] = 1;
    adjacencyMatrix[1][2] = 1;
    adjacencyMatrix[2][3] = 1;
    adjacencyMatrix[3][4] = 1;
}

// 添加边到邻接链表
void addEdgeToList(int v1, int v2) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v2;
    newNode->next = adjacencyList[v1];
    adjacencyList[v1] = newNode;
}

// 生成逆邻接链表
void generateInverseAdjacencyList(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        inverseAdjacencyList[i] = NULL;
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[j][i] == 1) {
                // 在逆邻接链表中添加边的起点
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->vertex = j;
                newNode->next = inverseAdjacencyList[i];
                inverseAdjacencyList[i] = newNode;
            }
        }
    }
}

// 打印邻接链表
void printAdjacencyList(int numVertices) {
    printf("Adjacency List:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d -> ", i);
        Node* current = adjacencyList[i];
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

// 打印逆邻接链表
void printInverseAdjacencyList(int numVertices) {
    printf("Inverse Adjacency List:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d -> ", i);
        Node* current = inverseAdjacencyList[i];
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    initAdjacencyMatrix();

    int numVertices = 5;

    // 初始化邻接链表和逆邻接链表
    for (int i = 0; i < numVertices; i++) {
        adjacencyList[i] = NULL;
        inverseAdjacencyList[i] = NULL;
    }

    // 生成邻接链表
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                addEdgeToList(i, j);
            }
        }
    }

    // 生成逆邻接链表
    generateInverseAdjacencyList(numVertices);

    // 打印邻接链表和逆邻接链表
    printAdjacencyList(numVertices);
    printInverseAdjacencyList(numVertices);

    return 0;
}

