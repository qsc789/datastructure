#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int size;
} Array;

void initArray(Array* arr) {
    arr->size = 0;
}

void insert(Array* arr, int value) {
    if (arr->size >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    arr->data[arr->size] = value;
    arr->size++;
}

void removeElement(Array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

int get(Array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index.\n");
        return -1;
    }
    return arr->data[index];
}

int main() {
    Array arr;
    initArray(&arr);
    insert(&arr, 10);
    insert(&arr, 20);
    insert(&arr, 30);
    insert(&arr, 40);
    insert(&arr, 50);

    printf("%d\n", get(&arr, 2)); // 输出第三个元素

    removeElement(&arr, 1); // 移除第二个元素

    for (int i = 0; i < arr.size; i++) {
        printf("%d ", get(&arr, i));
    }
    printf("\n");

    return 0;
}
