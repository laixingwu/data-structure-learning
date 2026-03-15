#pragma once

typedef  struct LSNode
{
	int data;
	struct LSNode* next;
}LSNode,*PLStack;

//初始化
void InitStack(PLStack ps);
//往栈中入数据(入栈操作)
bool Push(PLStack ps, int val);
//获取栈顶元素的值,但不删除
bool   GetTop(PLStack  ps, int* rtval);
//获取栈顶元素的值,并且删除
bool  Pop(PLStack ps, int* rtval);
//判空
bool IsEmpty(PLStack ps);
//获取栈中有效数据的个数
int GetLength(PLStack ps);
//清空所有的数据
void Clear(PLStack ps);
//销毁
void Destroy(PLStack ps);

