

#include "list.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//初始化
void   InitList(List  plist)
{
	assert(plist != NULL);
	if (plist == NULL)
		return;
	//plist->data;//头节点的数据域不使用;
	plist->next = NULL;
}

//头插,考试重点
bool  Insert_head(List  plist, int val)//O(1)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	//动态申请一个节点
	Node* p = (Node*)malloc(sizeof(Node));
	assert(p != NULL);

	//将数据val放入到新节点
	p->data = val;

	//插入新节点
	p->next = plist->next;//"绑线",先连接后面的
	plist->next = p;
	return  true;

}

//尾插,考试重点
bool  Insert_tail(List plist, int val)//O(n)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;
	//申请节点
	Node* p = (Node*)malloc(sizeof(Node));
	assert(p != NULL);

	//将数据val放入到新节点
	p->data = val;

	//找尾巴
	Node* q;
	for (q = plist; q->next != NULL; q = q->next)
	{
		;
	}
	//插入新节点
	p->next = q->next;//p->next=NULL;//OK
	q->next = p;

	return true;
}

//插入数据,在plist链表的pos位置插入val;//作业
bool   Insert(List plist, int pos, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;
	if (pos<0 || pos>Getlength(plist))
	{
		return false;
	}

	Node* p = (Node *)malloc(sizeof(Node));
	assert(p != NULL);
	p->data = val;

	//找到位置
	Node* q;
	int i;
	for ( q = plist,  i = 0; i < pos; i++, q = q->next)
	{
		;
	}
	//插入
	p->next = q->next;
	q->next = p;

	return true;
}

//判空
bool   IsEmpyt(List plist)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	//return plist->next == NULL;
	if (plist->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//获取数据节点的个数
int  Getlength(List plist)
{
	assert(plist != NULL);
	if (plist == NULL)
		return -1;

	int count = 0;
	for (Node* p = plist->next; p!= NULL; p = p->next)
	{
		count++;
	}
	return count;
}

//在plist中查找第一个key值,找到返回节点地址,没有找到返回NULL
Node* Search(List   plist, int key)
{
	assert(plist != NULL);
	if (plist == NULL)
		return NULL;

	for (Node* p =plist->next;p!=NULL ;p=p->next)
	{
		if (p->data == key)
		{
			return p;
		}
	}
	return NULL;
}


//删除pos位置的值.
bool   DelPos(List plist, int pos)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;

	if (pos<0 || pos>=Getlength(plist))
	{
		return false;
	}

	Node* p;
	int i;
	for (p = plist, i = 0; i < pos; i++, p = p->next)
	{
		;
	}
	//删除p后面的节点;
	Node* q = p->next;
	p->next = q->next;// p->next = p->next->next;//OK
	free(q);

	return true;
}

//删除第一个val的值
//考试重点
bool  DelVal(List plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
		return false;
	//获得前驱
	Node *p=GetPrio(plist, val);
	if (p == NULL)
	{
		return false;
	}
	//删除
	Node* q = p->next;
	p->next = q->next;//p->next = p->next->next;//OK

	//释放
	free(q);
	return true;
}

//返回key的前驱地址,如果不存在返回NULL
Node* GetPrio(List  plist, int key)
{
	assert(plist != NULL);
	if (plist == NULL)
		return NULL;

	for (Node* p = plist; p->next != NULL; p = p->next)
	{
		if (p->next->data == key)
		{
			return p;
		}
	}
	return NULL;
}


//返回key的后继地址,如果不存在返回NULL
Node* GetNext(List  plist, int key)
{
	assert(plist != NULL);
	if (plist == NULL)
		return NULL;

	Node* p = Search(plist, key);
	if (p == NULL)
		return NULL;

	return p->next;
}


//输出
void  Show(List  plist)
{
	assert(plist != NULL);
	if (plist == NULL)
		return;

	for (Node* p = plist->next;p!=NULL;p=p->next)
	{
		printf("%d  ", p->data);
	}
	printf("\n");
}

//清空数据
void  Clear(List plist)
{
	Destroy(plist);
}

//销毁整个内存
void   Destroy(List  plist)
{
	Node* p;
	//总是删除第一个数据节点
	while (plist->next != NULL)
	{
		p = plist->next;
		plist->next = p->next;
		free(p);
	}
}

//逆置链表
void  Reverse1(List  plist)
{
	assert(plist != NULL);
	if (plist == NULL||plist->next==NULL||plist->next->next==NULL)
	{
		return;
	}
	Node* p = plist->next;//前面的点
	Node* q = p->next;//后面的点
	Node* r;//后面所有还未处理的第一个点

	p->next = NULL;
	while (q != NULL)
	{
		r = q->next;
		q->next = p;//向后转
		p = q;
		q = r;
	}
	plist->next = p;
}

//必须掌握链表逆置,必考题
void  Reverse(List  plist)
{
	assert(plist != NULL);
	if (plist == NULL||plist->next==NULL||plist->next->next==NULL)
		return;

	Node* p = plist->next;
	Node* q = p->next;

	plist->next = NULL;//断开
    //利用头插把节点插入到链表中
	while (p != NULL)
	{
		q = p->next;

		p->next = plist->next;//头插
		plist->next = p;

		p = q;
	}
}





