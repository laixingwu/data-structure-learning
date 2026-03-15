#pragma once

typedef  struct  LPNode//数据节点
{
	int data;//数据域
	struct  LPNode* next;//后继指针
}LPNode;

typedef  struct HNode//链式队列的头节点
{
	struct LPNode *front;//队头指针,指向第一个数据节点
	struct LPNode *rear;//队尾指针,执行最后一个数据节点
}HNode,*PLQueue;

//初始化
void InitQueue(PLQueue pq);
//往队列中入数据(入队操作)
bool Push(PLQueue pq, int val);
//获取队头元素的值,但不删除
bool   GetTop(PLQueue   pq, int* rtval);
//获取队头元素的值,并且删除
bool  Pop(PLQueue pq, int* rtval);
//判空
bool IsEmpty(PLQueue  pq);
//获取队列中有效数据的个数
int GetLength(PLQueue pq);
//清空所有的数据
void Clear(PLQueue  pq);
//销毁
void Destroy(PLQueue  pq);

