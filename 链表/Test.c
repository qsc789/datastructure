#include"SList.h"

void TestList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

}
void TestList2()
{
	SLTNode* plist = NULL;
	

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

}
void TestList3()
{
	SLTNode* plist = NULL;


	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

}
void TestList4()
{
	SLTNode* plist = NULL;


	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	//找
	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while (pos)
	{
		printf("第%d个pos节点：%p->%d\n", i++, pos, pos->data);
       pos = SListFind(pos->next, 2);
	}

	//将3修改成30
	pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(plist);

}
void TestList5()
{
	SLTNode* plist = NULL;


	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SLTNode* pos1 = SListFind(plist, 1);
	if (pos1)
	{
		SListInsert(&plist, pos1, 10);
	}
	SListPrint(plist);

	SLTNode* pos2 = SListFind(plist, 3);
	if (pos2)
	{
		SListInsert(&plist, pos2, 30);
	}
	SListPrint(plist);

}
void TestList6()
{
	SLTNode* plist = NULL;

	//断言报错
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);
	SListDestroy(&plist);
}
int main()
{
	//TestList1(); 
	//TestList2();
	TestList3();
	//TestList4();
	//TestList5();
	return 0;
}