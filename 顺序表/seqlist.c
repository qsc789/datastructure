#include"seqlist.h"
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListInit(SL* ps)//初始化,也可在初始化时就开辟空间
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;

}
void SeqListDestory(SL* ps)
{
	free(ps->a);//释放空间
	ps->a = NULL;//防止野指针
	ps->capacity = ps->size = 0;
}
void SeqListCheckCapacity(SL* ps)
{
//扩容
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;//如果容量为0，就给4个，如果容量不为0，就扩容到2倍
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//扩容失败直接退出
		}
		ps->a = tmp;//tmp是指针变量，把新开的空间给a
		ps->capacity = newcapacity;
	}
}
void SeqListPushBack(SL* ps, SLDataType x)//尾插
{
	SeqListCheckCapacity(ps);
	//空间够，直接放
	ps->a[ps->size] = x;
	ps->size++;

	//SeqListInsert(ps, ps->size, x); 与尾插等效
}
void SeqListPopBack(SL* ps)//尾删
{
	//防止删多了，两种方式
	if (ps->size > 0)
	{
		ps->a[ps->size - 1] = 0;
		ps->size--;
	}
	/*assert(ps->size > 0);
	ps->size--;*/

}
void SeqListPushFront(SL* ps, SLDataType x)//头插
{
	SeqListCheckCapacity(ps);
	//数据往后挪
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
 	ps->a[0] = x;
	ps->size++;


	 //SeqListInsert(ps, 0, x); 与头插等效

}
void SeqListPopFront(SL* ps)//头删
{
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;

}
int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
//pos==ps->size时相当于尾插
	/*if (pos > ps->size || pos < 0)
	{
		printf("pos invalid\n");
		return;
	}*/
	assert(pos <= ps->size && pos >= 0);//括号里为假则报错
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	//挪数据
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;

}
void SeqListErase(SL* ps, int pos)
{
	assert(pos <= ps->size&&pos>=0);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}
