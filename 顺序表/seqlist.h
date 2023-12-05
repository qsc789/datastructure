//.h�ļ�������

//#pragma once//��ֹͷ�ļ��ظ�����
//#define N 1000
//typedef int SLDataType;//���ʲô�͸�ʲô�����
//
/////��̬˳���
//typedef struct seqlist
//{
//	int a[N];
//	int size;
//}SL;
//
////�ӿ�
//void SeqListInit(SL* ps);//��ʼ��
//
////��̬�ص㣺�������޷����� ȱ�㣺�޷����۵�׼ȷȷ������
//void SeqListPushBack(SL* ps, SLDataType x);//β��
//void SeqListPopBack(SL* ps);//βɾ
//void SeqListPushFront(SL* ps, SLDataType x);//ͷ��
//void SeqListPushFront(SL* ps);//ͷɾ


#pragma once//��ֹͷ�ļ��ظ�����
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;//���ʲô�͸�ʲô�����

///��̬˳���
typedef struct seqlist
{
	SLDataType* a;
	int size;
	int capacity;//��������
}SL;


void SeqListPrint(SL* ps);
//�ӿ� 
void SeqListInit(SL* ps);//��ʼ��
void SeqListDestory(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);//β��
void SeqListPopBack(SL* ps);//βɾ
void SeqListPushFront(SL* ps, SLDataType x);//ͷ��
void SeqListPopFront(SL* ps);//ͷɾ

int SeqListFind(SL* ps, SLDataType x);//�ڱ���Ѱ��Ԫ�أ�����λ�ã�û���򷵻�-1
void SeqListInsert(SL* ps, int pos, SLDataType x);//��ĳλ�ò���
void SeqListErase(SL* ps, int pos);//ɾ��posλ�õ�����