#include  "lstack.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//初始化
void InitStack(PLStack ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;
	ps->next = NULL;
}
//往栈中入数据(入栈操作)
bool Push(PLStack ps, int val)
{
	assert(ps != NULL);
	if (ps == NULL)
		return  false;

	LSNode* p = (LSNode*)malloc(sizeof(LSNode));
	assert(p != NULL);
	p->data = val;

	p->next = ps->next;//头插
	ps->next = p;

	return  true;

}
//获取栈顶元素的值,但不删除
bool   GetTop(PLStack  ps, int* rtval)
{
	assert(ps != NULL);
	if (ps == NULL)
		return  false;

	if (IsEmpty(ps))
	{
		return false;
	}

	*rtval = ps->next->data;
	return true;
}
//获取栈顶元素的值,并且删除
bool  Pop(PLStack ps, int* rtval)
{
	assert(ps != NULL);
	if (ps == NULL)
		return  false;

	if (IsEmpty(ps))
	{
		return false;
	}

	LSNode* p = ps->next;
	*rtval = p->data;

	ps->next = p->next;
	free(p);

	return true;

}
//判空
bool IsEmpty(PLStack ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return  false;

	return ps->next == NULL;
}
//获取栈中有效数据的个数
int GetLength(PLStack ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return  -1;

	int count = 0;
	for (LSNode* p = ps->next; p != NULL; p = p->next)
	{
		count++;
	}
	return count;
}
//清空所有的数据
void Clear(PLStack ps)
{
	Destroy(ps);
}
//销毁
void Destroy(PLStack ps)
{
	//总是删除第一个数据节点
	LSNode* p;
	while (ps->next != NULL)
	{
		p = ps->next;
		ps->next = p->next;
		free(p);
	}
}
