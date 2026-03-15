/*
int Max(int a, int b)
{
	return a > b ? a : b;
}
*/
#include  "sqlist.h"
#include <assert.h>
#include <stdio.h>
//初始化
void   InitSqlist(PSQList  ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;
	ps->length = 0;
}

static  bool  IsFul(PSQList ps)
{
	return  ps->length == 10;
}

//插入数据,在ps顺序表的pos位置插入val;
bool   Insert(PSQList ps, int pos, int val)
{
	//参数判断
	assert(ps != NULL);
	if (ps == NULL)
		return false;

	if (pos<0 || pos > ps->length || IsFul(ps))
	{
		return false;
	}
	
	//把数据移动到后面
	for (int i = ps->length - 1; i >= pos; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}
	//插入数据
	ps->elem[pos] = val;
	//有效数据个数++
	ps->length++;

	return true;
}

//判空
bool   IsEmpyt(PSQList ps)
{
	return ps->length == 0;
}

//在ps中查找第一个key值,找到返回下标,没有找到返回-1
int   Search(PSQList   ps, int key)
{
	assert(ps != NULL);
	if (ps == NULL)
	{
		return -1;
	}
	for (int i = 0; i < ps->length; i++)
	{
		if (key == ps->elem[i])
		{
			return i;
		}
	}
	return -1;
}


//删除pos位置的值
bool   DelPos(PSQList ps, int pos)
{
	//参数判断
	assert(ps != NULL);
	if (ps == NULL)
		return false;

	if (pos<0 || pos>=ps->length)
	{
		return false;
	}
	//将后面的数据前移
	for (int i = pos; i < ps->length - 1; i++)
	{
		ps->elem[i] = ps->elem[i + 1];
	}

	//有效数据个数--;
	ps->length--;
	return   true;
}

//删除第一个val的值
bool  DelVal(PSQList ps, int val)
{
	assert(ps != NULL);
	if (ps == NULL)
		return false;
	int  i = Search(ps, val);
	if (i < 0)
		return false;

	return DelPos(ps, i);

}

//返回key的前驱下标,如果不存在返回-1
int  GetPrio(PSQList  ps, int key)
{
	int i = Search(ps, key);
	if (i <= 0)//头没有前驱
		return -1;

	return i - 1;
}


//返回key的后继下标,如果不存在返回-1
int  GetNext(PSQList  ps, int key)
{
	int i = Search(ps, key);
	if (i < 0||i==ps->length-1)//注意,尾没有后继;
	{
		return -1;
	}

	return i + 1;
}


//输出
void  Show(PSQList  ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;
	for (int i = 0; i < ps->length; i++)
	{
		printf("%d ", ps->elem[i]);
	}
	printf("\n");
}

//清空数据
void  Clear(PSQList ps)
{
	ps->length = 0;
}

//销毁整个内存
void   Destroy(PSQList  ps)
{
	Clear(ps);
}