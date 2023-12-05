#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//ջ��
	int capacity;//����
}ST;//�ṹ������
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);//������
void StackPop(ST* ps);//������
STDataType StackTop(ST* ps);//ȡջ������
int StackSize(ST* ps);
bool StackEmpty(ST* ps);//�ж�ջ�Ƿ�Ϊ��
