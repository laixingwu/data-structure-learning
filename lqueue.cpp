#include "lqueue.h"
#include <assert.h>
#include  <stdlib.h>

//初始化
void InitQueue(PLQueue pq)
{
	assert(pq != NULL);

	if (pq == NULL)
		return;

	pq->front = NULL;
	pq->rear = NULL;
}
//往队列中入数据(入队操作)
bool Push(PLQueue pq, int val)
{
	assert(pq != NULL);
	if (pq == NULL)
		return false;

	//申请节点
	LPNode* p = (LPNode*)malloc(sizeof(LPNode));
	assert(p != NULL);
	p->data = val;
	p->next = NULL;//先绑后面;


	if (IsEmpty(pq))//第一次入队
	{
		pq->front = p;
		pq->rear = p;
	}
	else
	{
		pq->rear->next = p;//将p插入到队尾;
		pq->rear = p;
	}
	return true;

}
//获取队头元素的值,但不删除
bool   GetTop(PLQueue   pq, int* rtval)
{
	assert(pq != NULL);
	if (pq == NULL)
		return false;
	if (IsEmpty(pq))
	{
		return false;
	}
	*rtval = pq->front->data;
	return true;
}
//获取队头元素的值,并且删除
bool  Pop(PLQueue pq, int* rtval)
{
	assert(pq != NULL);
	if (pq == NULL)
		return false;
	if (IsEmpty(pq))
	{
		return false;
	}
	*rtval = pq->front->data;
	//删除第一个数据节点
	LPNode* p = pq->front;
	pq->front = p->next;
	free(p);

	if (pq->front == NULL)//删除最后一个节点
	{
		pq->rear = NULL;
	}
	return true;
}
//判空
bool IsEmpty(PLQueue  pq)
{
	assert(pq != NULL);
	if (pq == NULL)
		return false;

	return pq->front == NULL;
}
//获取队列中有效数据的个数
int GetLength(PLQueue pq)
{
	assert(pq != NULL);
	if (pq == NULL)
		return -1;

	int count = 0;
	for (LPNode* p = pq->front; p != NULL; p = p->next)
	{
		count++;
	}
	return count;

}
//清空所有的数据
void Clear(PLQueue  pq)
{
	Destroy(pq);
}
//销毁
void Destroy(PLQueue  pq)
{
	assert(pq != NULL);
	if (pq == NULL)
		return ;

	//总是删除第一个数据节点
	LPNode* p;
	while (pq->front != NULL)
	{
		p = pq->front;
		pq->front = p->next;
		free(p);
	}

	pq->rear = NULL;

}
