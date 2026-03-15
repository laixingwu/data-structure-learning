#include "queue.h"
#include <assert.h>
#include <stdlib.h>

//初始化
void InitQueue(PSqQueue pq)
{
	assert(pq != NULL);
	if (pq == NULL)
		return;

	pq->base = (int*)malloc(sizeof(int) * SIZE);
	assert(pq->base != NULL);
	pq->front = 0;
	pq->rear = 0;
}

static  bool  IsFull(PSqQueue pq)
{
	return  (pq->rear + 1) % SIZE == pq->front;
	//return pq->rear + 1 == pq->front;//error
}
//往队列中入数据(入队操作)
bool Push(PSqQueue pq, int val)
{
	assert(pq != NULL);
	if (pq == NULL)
	{
		return false;
	}
	if (IsFull(pq))
	{
		return false;
	}
	pq->base[pq->rear] = val;
	//pq->rear++;//error;必须处理成环形;
	pq->rear = (pq->rear + 1) % SIZE;
	return  true;
}
//获取队头元素的值,但不删除
bool   GetTop(PSqQueue   pq, int* rtval)
{
	assert(pq != NULL);
	if (pq == NULL)
	{
		return false;
	}

	if (IsEmpty(pq))
	{
		return false;
	}

	*rtval = pq->base[pq->front];
	return true;
}
//获取队头元素的值,并且删除
bool  Pop(PSqQueue pq, int* rtval)
{
	assert(pq != NULL);
	if (pq == NULL)
	{
		return false;
	}

	if (IsEmpty(pq))
	{
		return false;
	}

	*rtval = pq->base[pq->front];
	pq->front = (pq->front + 1) % SIZE;
	return true;
}
//判空
bool IsEmpty(PSqQueue  pq)
{
	assert(pq != NULL);
	if (pq == NULL)
	{
		return false;
	}

	return pq->front == pq->rear;
}
//获取队列中有效数据的个数
int GetLength(PSqQueue pq)
{
	assert(pq != NULL);
	if (pq == NULL)
	{
		return -1;
	}

	return (pq->rear - pq->front + SIZE) % SIZE;
}
//清空所有的数据
void Clear(PSqQueue  pq)
{
	assert(pq != NULL);
	if (pq == NULL)
	{
		return ;
	}

	pq->front = 0;
	pq->rear = 0;
}
//销毁
void Destroy(PSqQueue  pq)
{
	assert(pq != NULL);
	if (pq == NULL)
	{
		return ;
	}

	free(pq->base);
	pq->base = NULL;
	pq->front = 0;
	pq->rear = 0;
}