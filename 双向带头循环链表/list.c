#include"list.h"
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));//哨兵位头结点
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur=cur->next;

	}

	printf("\n");
}
void ListPushBack(LTNode* phead, LTDataType x)//有哨兵位，不用考虑空链表
{
	//不改变plist，不用传二级指针
	assert(phead);
	/*LTNode* tail = phead->prev;
	LTNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	ListInsert(phead, x);
}
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	free(tail);
	tailprev->next = phead;
	phead->prev = tailprev;*/
	ListErase(phead->prev);
	
}
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);

	LTNode* next = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = next;
	next->prev = newnode;*/
	ListInsert(phead->next, x);
}
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	/*LTNode* next = phead->next;
	LTNode* nextNext = next->next;

	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);*/
	ListErase(phead->next);
}
LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* posPrev = pos->prev;

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}

