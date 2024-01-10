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

LTNode* ListInit();//Ҫ���ö���ָ�룬Ҫ���з���ֵ
void ListPrint(LTNode* phead);
LTNode* BuyListNode(LTDataType x);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead, LTDataType x);

//��pos֮ǰ����
void ListInsert(LTNode* pos, LTDataType x);
//ɾ��pos
void ListErase(LTNode* pos);
