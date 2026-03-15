#pragma once

#define  INIT_SIZE 10
//顺序栈
typedef  struct  Stack
{
	int* base;//指向动态内存
	int  top;//栈顶指针,实际是下标,也就是当前可以存放数据的下标
	int  stacksize;//栈的总大小
}Stack,*PStack;

//初始化
void InitStack(PStack ps);
//往栈中入数据(入栈操作)
bool Push(PStack ps, int val);
//获取栈顶元素的值,但不删除
bool   GetTop(PStack  ps,int *rtval);
//获取栈顶元素的值,并且删除
bool  Pop(PStack ps, int* rtval);
//判空
bool IsEmpty(PStack ps);
//获取栈中有效数据的个数
int GetLength(PStack ps);
//清空所有的数据
void Clear(PStack ps);
//销毁
void Destroy(PStack ps);
