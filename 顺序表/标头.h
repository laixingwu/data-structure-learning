#pragma once

typedef struct  Node
{
	int data;//数据域
	struct Node* next;
}Node, * List;


//初始化
void   InitList(List  plist);

//头插
bool  Insert_head(List  plist, int val);

//尾插
bool  Insert_tail(List plist, int val);

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


