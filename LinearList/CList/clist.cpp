#include "clist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//初始化
void   InitCList(CList  plist)
{
	assert(plist != NULL);
	if (plist == NULL)
		return;
	//头节点的数据域不使用
	plist->next = plist;
}

//头插,考试重点
bool  Insert_head(CList  plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	//申请节点
	CNode* p = (CNode*)malloc(sizeof(CNode));
	assert(p != NULL);
	//放入数据
	p->data = val;
	//头插
	p->next = plist->next;
	plist->next = p;

	return true;
}

//尾插,考试重点
bool  Insert_tail(CList plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	//创建新节点
	CNode* p = (CNode*)malloc(sizeof(CNode));
	assert(p != NULL);
	//放入数据
	p->data = val;
	//找尾巴
	CNode* q;
	for (q = plist; q->next != plist; q = q->next)
	{
		;
	}
	//尾插
	p->next = q->next;//p->next=plist;//OK
	q->next = p;

	return true;
}

//插入数据,在plist链表的pos位置插入val;
bool   Insert(CList plist, int pos, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;
	if (pos<0 || pos>Getlength(plist))
	{
		return false;
	}
	//申请节点
	CNode* p = (CNode*)malloc(sizeof(CNode));
	assert(p != NULL);
	//放入数据
	p->data = val;
	//找位置
	int i = 0;
	CNode* q;
	for (q = plist; i < pos; i++, q = q->next)
	{
		;
	}

	//插入
	p->next = q->next;
	q->next = p;

	return true;
}

//判空
bool   IsEmpyt(CList plist)
{
	return plist->next == plist;
}

//获取数据节点的个数
int  Getlength(CList plist)
{
	assert(plist != NULL);
	if (plist == NULL)
		return -1;

	int count = 0;
	for (CNode* p = plist->next; p != plist; p = p->next)
	{
		count++;
	}

	return count;
}

//在plist中查找第一个key值,找到返回节点地址,没有找到返回NULL
CNode* Search(CList   plist, int key)
{
	assert(plist != NULL);
	if (plist == NULL)
		return NULL;

	for (CNode* p = plist->next;p!=plist;p=p->next)
	{
		if (p->data == key)
		{
			return p;
		}
	}
	return NULL;
}


//删除pos位置的值
bool   DelPos(CList plist, int pos)
{
	if (pos < 0 || pos >= Getlength(plist))
		return false;

	CNode* p;
	int i;
	for (p = plist, i = 0; i < pos; i++, p = p->next)
	{
		;
	}

	CNode* q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

//删除第一个val的值,考点
bool  DelVal(CList plist, int val)
{
	CNode* p = GetPrio(plist, val);
	if (p == NULL)
		return false;

	CNode* q = p->next;
	p->next = q->next;
	free(q);

	return true;
}

//返回key的前驱地址,如果不存在返回NULL
CNode* GetPrio(CList  plist, int key)
{
	for (CNode* p = plist; p->next != plist; p = p->next)
	{
		if (p->next->data == key)
		{
			return p;
		}
	}
	return NULL;
}


//返回key的后继地址,如果不存在返回NULL
CNode* GetNext(CList  plist, int key)
{
	CNode* p = Search(plist, key);
	if (p == NULL)
		return NULL;

	return p->next;
}


//输出
void  Show(CList  plist)
{
	for (CNode* p = plist->next;p!=plist;p=p->next)
	{
		printf("%d  ", p->data);
	}
	printf("\n");
}

//清空数据
void  Clear(CList plist)
{
	Destroy(plist);
}

//销毁整个内存
void   Destroy(CList  plist)
{
	//总是删除第一个数据节点
	CNode* p;
	while (plist->next != plist)
	{
		p = plist->next;
		plist->next = p->next;
		free(p);
	}
}
