#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;//容量
}ST;//结构体类型
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);//进数据
void StackPop(ST* ps);//出数据
STDataType StackTop(ST* ps);//取栈顶数据
int StackSize(ST* ps);
bool StackEmpty(ST* ps);//判断栈是否为空
