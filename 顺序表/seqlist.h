//.h文件放声明

//#pragma once//防止头文件重复引用
//#define N 1000
//typedef int SLDataType;//想存什么就给什么起别名
//
/////静态顺序表
//typedef struct seqlist
//{
//	int a[N];
//	int size;
//}SL;
//
////接口
//void SeqListInit(SL* ps);//初始化
//
////静态特点：满了则无法插入 缺点：无法主观的准确确定容量
//void SeqListPushBack(SL* ps, SLDataType x);//尾插
//void SeqListPopBack(SL* ps);//尾删
//void SeqListPushFront(SL* ps, SLDataType x);//头插
//void SeqListPushFront(SL* ps);//头删


#pragma once//防止头文件重复引用
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;//想存什么就给什么起别名

///动态顺序表
typedef struct seqlist
{
	SLDataType* a;
	int size;
	int capacity;//现有容量
}SL;


void SeqListPrint(SL* ps);
//接口 
void SeqListInit(SL* ps);//初始化
void SeqListDestory(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);//尾插
void SeqListPopBack(SL* ps);//尾删
void SeqListPushFront(SL* ps, SLDataType x);//头插
void SeqListPopFront(SL* ps);//头删

int SeqListFind(SL* ps, SLDataType x);//在表中寻找元素，返回位置，没有则返回-1
void SeqListInsert(SL* ps, int pos, SLDataType x);//在某位置插入
void SeqListErase(SL* ps, int pos);//删除pos位置的数据