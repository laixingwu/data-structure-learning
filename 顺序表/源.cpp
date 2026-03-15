#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include"标头.h"
#include <assert.h>


//初始化
void   InitList(List  plist)
{
	plist = (Node*)malloc(sizeof(Node));
	assert(plist != NULL);
	if (plist == NULL)
	{
		return ;
	}
	plist->next = NULL;
	printf("初始化成功\n");
}

//头插
bool  Insert_head(List  plist)
{
	int val;
	List s;
	printf("请输入需要插入的数据,以0结尾\n");
	scanf("%d", &val);
	while (val != 0)
	{
		s = (Node*)malloc(sizeof(Node));
		s->next = plist->next;
		plist->next = s;
		s->data = val;
		scanf("%d", &val);
	}
	printf("录入单链表成功\n");
	return true;

}

//尾插
bool  Insert_tail(List plist)
{
	int val;
	List s,r;
	printf("请输入需要插入的数据,以999结尾\n");
	scanf("%d", &val);
	r = plist;
	while (val != 999)
	{
		s = (Node*)malloc(sizeof(Node));
		r->next = s;
		r = s;
		s->data = val;
		scanf("%d", &val);
	}
	r->next = NULL;
	return true;

}

//插入数据,在plist链表的pos位置插入val;
bool   Insert(List plist, int pos, int val);

//判空
bool   IsEmpyt(List plist);

//获取数据节点的个数
int  Getlength(List plist);

//在plist中查找第一个key值,找到返回节点地址,没有找到返回NULL
Node* Search(List   plist, int key);


//删除pos位置的值
bool   DelPos(List plist, int pos);

//删除第一个val的值
bool  DelVal(List plist, int val);

//返回key的前驱地址,如果不存在返回NULL
Node* GetPrio(List  plist, int key);


//返回key的后继地址,如果不存在返回NULL
Node* GetNext(List  plist, int key);

void Show(List  plist)
{
	assert(plist != NULL);
	if (plist==NULL)
	{
		return;
	}
	Node* 	p = plist->next;
	printf("输出单链表为\n");
	while (p != NULL)
	{		
		printf("%d ", p->data);
		p = p->next;
	}

}


int main()
{
	Node head;
	InitList(&head);
	//Insert_tail(&head);
	Insert_head(&head);
	Show(&head);
}
