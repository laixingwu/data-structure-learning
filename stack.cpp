#include "stack.h"
#include <assert.h>
#include <stdlib.h>
//初始化
void InitStack(PStack ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;

	ps->base = (int*)malloc(INIT_SIZE * sizeof(int));
	assert(ps->base != NULL);

	ps->top = 0;
	ps->stacksize = INIT_SIZE;
}

static  bool  IsFull(PStack  ps)
{
	return ps->top == ps->stacksize;
}

static void  Inc(PStack ps)
{
	ps->stacksize *= 2;
	ps->base = (int*)realloc(ps->base, ps->stacksize * sizeof(int));
	assert(ps->base != NULL);
}

//往栈中入数据(入栈操作)//O(1)
bool Push(PStack ps, int val)
{
	assert(ps != NULL);
	if (ps == NULL)
		return  false;
	if (IsFull(ps))
	{
		Inc(ps);
	}
	ps->base[ps->top++] = val;
	//ps->top++;

	return true;
}

//获取栈顶元素的值,但不删除
//输出参数
bool  GetTop(PStack  ps,int *rtval)//O(1)
{
	assert(ps != NULL);
	if (ps == NULL)
	{
		return   false;
	}
	if (IsEmpty(ps))
	{
		return false;
	}

	*rtval= ps->base[ps->top - 1];
	
	return true;
}

//获取栈顶元素的值,并且删除
bool  Pop(PStack ps,int *rtval)//O(1)
{
	assert(ps != NULL);
	if (ps == NULL)
		return false;

	if (IsEmpty(ps))
	{
		return false;
	}

	//*rtval = ps->base[ps->top - 1];
	//ps->top--;

	*rtval = ps->base[--ps->top];
	return true;
}

//判空
bool IsEmpty(PStack ps)
{
	return ps->top == 0;
}

//获取栈中有效数据的个数
int GetLength(PStack ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return -1;

	return  ps->top;
}

//清空所有的数据
void Clear(PStack ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;

	ps->top = 0;
}

//销毁
void Destroy(PStack ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;

	free(ps->base);
	ps->base = NULL;
	ps->top = 0;
	ps->stacksize = 0;
}
