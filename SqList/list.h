
#pragma once
//单链表的特点:
//头插,头删的时间复杂度是O(1)
//尾插,尾删的时间复杂度是O(n)

//如果我们要修改表的结构(或者说依赖于前驱,比如插入,删除):遍历:
// for(Node *p=plist;p->next!=NULL;p=p->next)
//如果我们不修改表的结构(或者说不依赖于前驱, 比如求长度,打印,查找) :遍历:
//for (Node* p = plist->next; p != NULL; p = p->next)
typedef struct  Node
{
	int data;//数据域
	struct Node* next;
}Node,*List;
//Node *==List


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
Node * Search(List   plist, int key);


//删除pos位置的值
bool   DelPos(List plist, int pos);

//删除第一个val的值
bool  DelVal(List plist, int val);

//返回key的前驱地址,如果不存在返回NULL
Node * GetPrio(List  plist, int key);


//返回key的后继地址,如果不存在返回NULL
Node * GetNext(List  plist, int key);


//输出
void  Show(List  plist);

//清空数据
void  Clear(List plist);

//销毁整个内存
void   Destroy(List  plist);

//逆置链表
void  Reverse(List  plist);


