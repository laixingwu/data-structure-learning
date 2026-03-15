#pragma once

#define  MAXSIZE 10
typedef struct  SNode
{
	int data;//数据域
	int next;//后继指针(下标)
}SNode,SLinkList[MAXSIZE];

//SLinkList s;//s是长度为MAXSIZE的结构体数组

//初始化
void   InitList(SNode *  ps);
//头插
bool  Insert_head(SNode *  ps, int val);
//尾插
bool  Insert_tail(SNode* ps, int val);
//判空
bool   IsEmpyt(SNode * ps);
//获取数据节点的个数
int  Getlength(SNode* ps);
//在ps中查找第一个key值,找到返回节点下标,没有找到返回-1
int  Search(SNode*   ps, int key);
//删除第一个val的值
bool  DelVal(SNode* ps, int val);
//输出
void  Show(SNode * ps);
//清空数据
void  Clear(SNode* ps);
//销毁整个内存
void   Destroy(SNode*   ps);
