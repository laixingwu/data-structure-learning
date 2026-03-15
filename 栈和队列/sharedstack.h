#pragma once
#define STACK_SIZE 10
typedef  struct  SharedStack
{
	int elem[STACK_SIZE];
	int top1;
	int top2;
}SharedStack,*PSharedStack;

//初始化
void  InitSharedStack(PSharedStack ps);

//入栈
//no标记从1栈入还是从2栈入
bool  Push(PSharedStack ps, int val,int no);

//出栈
bool  Pop(PSharedStack ps, int* rtval, int no);

//判空
bool IsEmpty1(PSharedStack ps);//判断1栈是否为空栈
bool IsEmpty2(PSharedStack ps);//判断2栈是否为空栈


