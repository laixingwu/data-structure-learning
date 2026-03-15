

#pragma once


//循环链表
typedef struct CNode
{
	int  data;
	struct  CNode*next;
}CNode,*CList;
//CList==CNode *

//初始化
void   InitCList(CList  plist);

//头插
bool  Insert_head(CList  plist, int val);

//尾插
bool  Insert_tail(CList plist, int val);

//插入数据,在plist链表的pos位置插入val;
bool   Insert(CList plist, int pos, int val);

//判空
bool   IsEmpyt(CList plist);

//获取数据节点的个数
int  Getlength(CList plist);

//在plist中查找第一个key值,找到返回节点地址,没有找到返回NULL
CNode* Search(CList   plist, int key);


//删除pos位置的值
bool   DelPos(CList plist, int pos);

//删除第一个val的值
bool  DelVal(CList plist, int val);

//返回key的前驱地址,如果不存在返回NULL
CNode* GetPrio(CList  plist, int key);


//返回key的后继地址,如果不存在返回NULL
CNode* GetNext(CList  plist, int key);


//输出
void  Show(CList  plist);

//清空数据
void  Clear(CList plist);

//销毁整个内存
void   Destroy(CList  plist);
