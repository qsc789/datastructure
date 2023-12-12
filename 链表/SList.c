 #include"SList.h"

SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;//malloc新节点

	return newnode;
}
void SListPrint(SLTNode* phead)
{
	//cur和phead都指向链表第一个元素
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//next是一个指针，指向下一个节点
	}
	printf("NULL\n");
 }
void SListPushBack(SLTNode** pphead, SLTDataType x)//尾插
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	
	if (*pphead == NULL)//链表首元素地址为空，链表为空
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
	
}
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);//newnode是结构体指针
   
	//把节点往前加
	newnode->next = *pphead;
	*pphead = newnode;


}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);//链表为空
	if ((*pphead)->next == NULL)//只有一个元素
	{
		free(*pphead);
		*pphead = NULL;

	}
	else//多个元素
	{
		SLTNode* prev = NULL;//存前一个元素地址
		SLTNode* tail = *pphead;
		while (tail->next)//为空则为假
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}

}
void SListPopFront(SLTNode** pphead)//plist地址
{
	assert(pphead);
	assert(*pphead);
	SLTNode* cur = *pphead;
	*pphead= (*pphead)->next;//保存下一个
	free(cur);
	
}
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}

	}
	return NULL;
}
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
     SLTNode* posPrev = *pphead;
	   while (posPrev->next != pos)
	  {
		posPrev = posPrev->next;
	  }
	  posPrev->next = newnode;
	  newnode->next = pos;
	}
	

}
void SListEraseAfter(SLTNode* pos)
{
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;//可以不置空
}
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	if (*pphead == pos)
	{
		//*pphead = pos->next;
		//free(pos);
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SListDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}