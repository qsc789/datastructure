#include"list.h"
void TestList1()
{
	LTNode* plist =	ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	//ListPopBack(plist);
	ListPrint(plist);

}
void TestList2()
{
	LTNode* plist = ListInit();

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);
	plist = NULL;
}
int main()
{
	TestList1();
	return 0;
}