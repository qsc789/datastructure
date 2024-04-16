#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int freq;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* createNode(char data, int freq) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildHuffmanTree(char data[], int freq[], int n) {
    Node** nodes = (Node**)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(data[i], freq[i]);
    }

    while (n > 1) {
        Node* left = nodes[n-1];
        Node* right = nodes[n-2];

        Node* parent = createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        int k = n - 2;
        while (k > 0 && nodes[k-1]->freq < parent->freq) {
            nodes[k] = nodes[k-1];
            k--;
        }
        nodes[k] = parent;

        n--;
    }

    return nodes[0];
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {5, 9, 12, 13, 16};
    int n = sizeof(data) / sizeof(data[0]);

    Node* root = buildHuffmanTree(data, freq, n);

    // 这里可以添加打印哈夫曼树的代码

    return 0;
}
