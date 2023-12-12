#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead,SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//在pos位置之后插入一个节点
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//在pos位置之前插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListEraseAfter(SLTNode* pos);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListDestroy(SLTNode** pphead);