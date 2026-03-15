#include "dlist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//初始化
void   InitList(DList  plist)
{
	assert(plist != NULL);
	if (plist == NULL)
		return;
	plist->next = NULL;
	plist->prio = NULL;
}

//头插
bool  Insert_head(DList  plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	//创建新节点
	DNode* p = (DNode*)malloc(sizeof(DNode));
	assert(p != NULL);
	p->data = val;

	//插入新节点
	p->next = plist->next;
	plist->next = p;
	p->prio = plist;
	if (p->next != NULL)//考点
	{
		p->next->prio = p;
	}
	return true;
}

//尾插
bool  Insert_tail(DList plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	//创建新节点
	DNode * p = (DNode*)malloc(sizeof(DNode));
	assert(p != NULL);
	p->data = val;

	//找尾巴
	DNode* q;
	for (q = plist; q->next != NULL; q = q->next)
	{
		;
	}
	//将p插入到q的后面
	p->next = q->next;
	q->next = p;
	p->prio = q;

	return true;

}

//插入数据,在plist链表的pos位置插入val;
bool   Insert(DList plist, int pos, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	if (pos<0 || pos>Getlength(plist))
	{
		return false;
	}
	//申请节点
	DNode* p = (DNode*)malloc(sizeof(DNode));
	assert(p != NULL);
	p->data = val;

	//找位置
	DNode* q;
	int i = 0;
	for (q = plist; i < pos; i++, q = q->next)
	{
		;
	}
	//插入数据
	//将p插入到q的后面
	p->next = q->next;
	q->next = p;
	p->prio = q;
	if (p->next != NULL)
	{
		p->next->prio = p;
	}
	return true;
}

//判空
bool   IsEmpyt(DList plist)
{
	return plist->next == NULL;
}

//获取数据节点的个数
int  Getlength(DList plist)
{
	int count = 0;
	for (DNode* p = plist->next; p != NULL; p = p->next)
	{
		count++;
	}
	return count;
}

//在plist中查找第一个key值,找到返回节点地址,没有找到返回NULL
DNode* Search(DList   plist, int key)
{
	for (DNode* p = plist->next; p != NULL; p = p->next)
	{
		if (p->data == key)
		{
			return p;
		}
	}
	return NULL;
}


//删除pos位置的值
bool   DelPos(DList plist, int pos)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	if (pos<0 || pos>=Getlength(plist))
	{
		return false;
	}

	//找位置
	DNode* p;
	int i = 0;
	for (p = plist; i < pos; i++, p = p->next)
	{
		;
	}

	DNode* q = p->next;//q是要删除的点
	p->next = q->next;

	if (q->next != NULL)
	{
		q->next->prio = q->prio;
	}

	free(q);
	return true;
}

//删除第一个val的值,考试重点
bool  DelVal(DList plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	DNode* p = Search(plist, val);
	if (p == NULL)
		return false;

	p->prio->next = p->next;
	if (p->next != NULL)
	{
		p->next->prio = p->prio;
	}	
	free(p);
	return true;

}

//返回key的前驱地址,如果不存在返回NULL
DNode* GetPrio(DList  plist, int key)
{
	DNode* p = Search(plist, key);

	return p == NULL ? NULL : p->prio;
}


//返回key的后继地址,如果不存在返回NULL
DNode* GetNext(DList  plist, int key)
{
	DNode* p = Search(plist, key);

	return p == NULL ? NULL : p->next;
}


//输出
void  Show(DList  plist)
{
	for (DNode* p = plist->next; p != NULL; p = p->next)
	{
		printf("%d  ", p->data);
	}

	printf("\n");
}

//清空数据
void  Clear(DList plist)
{
	Destroy(plist);
}

//销毁整个内存
void   Destroy(DList  plist)
{
	assert(plist != NULL);
	if (plist == NULL)
		return;

	//总是删除第一个节点
	DNode* p;
	while (plist->next != NULL)
	{
		p = plist->next;
		plist->next = p->next;

		//不用处理前驱
		/*if (p->next != NULL)
		{
			p->next->prio = plist;
		}*/
		free(p);
	}
}
