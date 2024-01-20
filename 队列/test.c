#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
void test1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("%d\n", QueueBack(&q)); 
	QueuePush(&q, 10);
	QueuePush(&q, 20); 

	QueueDestroy(&q);
}

int main()
{
	test1();
	return 0;
} 