#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;

}LTNode;

LTNode* ListInit();//要不用二级指针，要不有返回值
void ListPrint(LTNode* phead);
LTNode* BuyListNode(LTDataType x);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead, LTDataType x);

//在pos之前插入
void ListInsert(LTNode* pos, LTDataType x);
//删除pos
void ListErase(LTNode* pos);
