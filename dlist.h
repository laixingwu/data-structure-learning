#pragma once

//双向链表
typedef  struct  DNode
{
	int  data;
	struct  DNode*next;//后继指针
	struct  DNode *prio;//前驱指针
}DNode,*DList;

//初始化
void   InitList(DList  plist);

//头插
bool  Insert_head(DList  plist, int val);

//尾插
bool  Insert_tail(DList plist, int val);

//插入数据,在plist链表的pos位置插入val;
bool   Insert(DList plist, int pos, int val);

//判空
bool   IsEmpyt(DList plist);

//获取数据节点的个数
int  Getlength(DList plist);

//在plist中查找第一个key值,找到返回节点地址,没有找到返回NULL
DNode* Search(DList   plist, int key);


//删除pos位置的值
bool   DelPos(DList plist, int pos);

//删除第一个val的值
bool  DelVal(DList plist, int val);

//返回key的前驱地址,如果不存在返回NULL
DNode* GetPrio(DList  plist, int key);


//返回key的后继地址,如果不存在返回NULL
DNode* GetNext(DList  plist, int key);


//输出
void  Show(DList  plist);

//清空数据
void  Clear(DList plist);

//销毁整个内存
void   Destroy(DList  plist);


