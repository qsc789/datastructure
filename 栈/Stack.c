
#include"Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//ps->top=-1;
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x)//进数据
{
	assert(ps);
	if (ps->top == ps->capacity)//扩容
	{
		int newCapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);//扩容
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)//出数据
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

STDataType StackTop(ST* ps)//取栈顶数据
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)//判断栈是否为空
{
	assert(ps);//断言
	return ps->top == 0;//反的
}