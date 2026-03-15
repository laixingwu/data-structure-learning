#pragma once
//防止头文件被重复引用
//定长顺序表

//定义与声明
//int Max(int  a, int b);

typedef   struct  SQList
{
	int  elem[10];//存放数据,固定长度为10
	int  length;//有效数据的长度
}SQList,*PSQList;

//初始化
void   InitSqlist(PSQList  ps);

//插入数据,在ps顺序表的pos位置插入val;
bool   Insert(PSQList ps, int pos, int val);

//判空
bool   IsEmpyt(PSQList ps);

//在ps中查找第一个key值,找到返回下标,没有找到返回-1
int   Search(PSQList   ps, int key);


//删除pos位置的值
bool   DelPos(PSQList ps, int pos);

//删除第一个val的值
bool  DelVal(PSQList ps, int val);

//返回key的前驱下标,如果不存在返回-1
int  GetPrio(PSQList  ps, int key);


//返回key的后继下标,如果不存在返回-1
int  GetNext(PSQList  ps, int key);


//输出
void  Show(PSQList  ps);

//清空数据
void  Clear(PSQList ps);

//销毁整个内存
void   Destroy(PSQList  ps);