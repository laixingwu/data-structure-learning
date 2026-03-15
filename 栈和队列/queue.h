#pragma once

#define SIZE 10
//循环队列
typedef  struct  SqQueue
{
	int  *base;//指向动态内存
	int  front;//队头指针,队头元素的下标;
	int rear;//队尾指针,当前可以插入数据的下标;
	//int  queuesize;//队列的总容量,要做到自动扩容就必须增加这个成员
}SqQueue,*PSqQueue;

//初始化
void InitQueue(PSqQueue pq);
//往队列中入数据(入队操作)
bool Push(PSqQueue pq, int val);
//获取队头元素的值,但不删除
bool   GetTop(PSqQueue   pq, int* rtval);
//获取队头元素的值,并且删除
bool  Pop(PSqQueue pq, int* rtval);
//判空
bool IsEmpty(PSqQueue  pq);
//获取队列中有效数据的个数
int GetLength(PSqQueue pq);
//清空所有的数据
void Clear(PSqQueue  pq);
//销毁
void Destroy(PSqQueue  pq);
