#include "slist.h"
#include <assert.h>
#include <stdio.h>
//初始化
void   InitList(SNode* ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;
	//处理有效链表
	ps[0].next = 0;
	//处理空闲链表
	for (int i = 1; i < MAXSIZE; i++)
	{
		ps[i].next = i + 1;
	}
	ps[MAXSIZE - 1].next = 1;
}

static  bool  IsFull(SNode* ps)
{
	return   ps[1].next == 1;
}
//头插
bool  Insert_head(SNode* ps, int val)
{
	if (IsFull(ps))
	{
		return false;
	}
	//获取一个空闲节点
	int p = ps[1].next;
	//将空闲节点从空闲链表中剔除
	ps[1].next = ps[p].next;
	//放入数据
	ps[p].data = val;
	//将空闲节点插入到有效链表中
	ps[p].next = ps[0].next;
	ps[0].next = p;

	return true;
}
//尾插
bool  Insert_tail(SNode* ps, int val)
{
	if (IsFull(ps))
	{
		return false;
	}

	//找到第一个空闲节点
	int  p = ps[1].next;
	//将空闲节点从空闲链表中剔除
	ps[1].next = ps[p].next;
	//放入数据
	ps[p].data = val;
	//找尾巴
	int q;
	for (q = 0; ps[q].next != 0; q = ps[q].next)
	{
		;
	}
	//将节点插入到有效链表中,p插入到q的后面
	ps[p].next = ps[q].next;
	ps[q].next = p;

	return true;
}
//判空
bool   IsEmpyt(SNode* ps)
{
	return ps[0].next == 0;//有效数据链表没有数据节点
}
//获取数据节点的个数
int  Getlength(SNode* ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return  -1;

	int count = 0;
	for (int p = ps[0].next; p != 0; p = ps[p].next)
	{
		count++;
	}
	return count;
}
//在ps中查找第一个key值,找到返回节点下标,没有找到返回-1
int  Search(SNode* ps, int key)
{
	assert(ps != NULL);
	if (ps == NULL)
		return  -1;
	//遍历有效链表
	for (int p = ps[0].next; p != 0; p = ps[p].next)
	{
		if (ps[p].data == key)
		{
			return p;
		}
	}
	return  -1;
}

int  GetPrio(SNode* ps, int key)
{
	for (int p = 0; ps[p].next != 0; p = ps[p].next)
	{
		//if(ps[ps[p].next].data==key)
		int q = ps[p].next;//p的后继
		if (ps[q].data == key)
		{
			return p;
		}
	}
	return -1;
}
//删除第一个val的值
bool  DelVal(SNode* ps, int val)
{
	int p = GetPrio(ps, val);
	if (p < 0)
	{
		return false;
	}

	//将节点从有效数据链表中删除
	int  q = ps[p].next;
	ps[p].next = ps[q].next;

	//将节点插入到空闲链表中
	ps[q].next = ps[1].next;
	ps[1].next = q;

	return true;
}


//输出
void  Show(SNode* ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;

	for (int p = ps[0].next; p != 0; p = ps[p].next)
	{
		printf("%d  ", ps[p].data);
	}
	printf("\n");
}
//清空数据
void  Clear(SNode* ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;

	InitList(ps);
}
//销毁整个内存
void   Destroy(SNode* ps)
{
	Clear(ps);
}
