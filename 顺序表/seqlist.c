#include"seqlist.h"
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListInit(SL* ps)//��ʼ��,Ҳ���ڳ�ʼ��ʱ�Ϳ��ٿռ�
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;

}
void SeqListDestory(SL* ps)
{
	free(ps->a);//�ͷſռ�
	ps->a = NULL;//��ֹҰָ��
	ps->capacity = ps->size = 0;
}
void SeqListCheckCapacity(SL* ps)
{
//����
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;//�������Ϊ0���͸�4�������������Ϊ0�������ݵ�2��
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//����ʧ��ֱ���˳�
		}
		ps->a = tmp;//tmp��ָ����������¿��Ŀռ��a
		ps->capacity = newcapacity;
	}
}
void SeqListPushBack(SL* ps, SLDataType x)//β��
{
	SeqListCheckCapacity(ps);
	//�ռ乻��ֱ�ӷ�
	ps->a[ps->size] = x;
	ps->size++;

	//SeqListInsert(ps, ps->size, x); ��β���Ч
}
void SeqListPopBack(SL* ps)//βɾ
{
	//��ֹɾ���ˣ����ַ�ʽ
	if (ps->size > 0)
	{
		ps->a[ps->size - 1] = 0;
		ps->size--;
	}
	/*assert(ps->size > 0);
	ps->size--;*/

}
void SeqListPushFront(SL* ps, SLDataType x)//ͷ��
{
	SeqListCheckCapacity(ps);
	//��������Ų
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
 	ps->a[0] = x;
	ps->size++;


	 //SeqListInsert(ps, 0, x); ��ͷ���Ч

}
void SeqListPopFront(SL* ps)//ͷɾ
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
//pos==ps->sizeʱ�൱��β��
	/*if (pos > ps->size || pos < 0)
	{
		printf("pos invalid\n");
		return;
	}*/
	assert(pos <= ps->size && pos >= 0);//������Ϊ���򱨴�
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	//Ų����
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
