
#include "seqlist.h"
void TestSeqList1()
{
	SL sl;//����һ���ṹ��
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	SeqListDestory(&sl);
}
void TestSeqList2()
{
	SL sl;//����һ���ṹ��
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListDestory(&sl);
}
void TestSeqList3()
{
	SL sl;//����һ���ṹ��
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	SeqListInsert(&sl, 2, 30);//�����30λ�ڵ���λ��ps->a[2]=30
    SeqListPrint(&sl);
	SeqListDestory(&sl);
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();

	return 0;
}
