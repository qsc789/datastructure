#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;

}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq,QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);//取队头数据
QDataType QueueBack(Queue* pq);//取队尾数据
int QueueSize(Queue* pq);//计算队里有多少数据
bool QueueEmpty(Queue* pq);