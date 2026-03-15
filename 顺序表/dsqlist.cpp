#include "dsqlist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//初始化
void   InitDSqlist(DPSQList  ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;
	ps->elem = (int*)malloc(INIT_SIZE * sizeof(int));
	ps->length = 0;
	ps->listsize = INIT_SIZE;
}

static  bool  IsFull(DPSQList ps)
{
	return ps->length == ps->listsize;
}
static bool  Inc(DPSQList ps)     
{
	ps->elem=(int *)realloc(ps->elem, ps->listsize * 2 * sizeof(int));
	assert(ps->elem != NULL);
	if (ps->elem == NULL)
		return false;
	ps->listsize *= 2;
	return true;
}
//插入数据,在ps顺序表的pos位置插入val;
bool   Insert(DPSQList ps, int pos, int val)
{
	//参数判断
	assert(ps != NULL);
	if (ps == NULL)
		return  false;
	if (pos<0 || pos>ps->length)
	{
		return false;
	}
	//满了扩容
	if (IsFull(ps))
	{
		Inc(ps);//扩容
	}
	//把数据往后移动
	for (int i = ps->length - 1; i >= pos; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}
	//插入新数据
	ps->elem[pos] = val;
	//有效数据个数++;
	ps->length++;
	return true;
}

//判空
bool   IsEmpyt(DPSQList ps)
{
	return  ps->length == 0;
}

//在ps中查找第一个key值,找到返回下标,没有找到返回-1
int   Search(DPSQList   ps, int key)
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
bool   DelPos(DPSQList ps, int pos)
{
	assert(ps != NULL);
	if (ps == NULL)
		return false;

	if (pos < 0 || pos >= ps->length)
	{
		return false;
	}

	//后面的数据前移
	for (int i = pos; i < ps->length - 1; i++)
	{
		ps->elem[i] = ps->elem[i + 1];   //i+1<ps->length
	}

	//有效数据--
	ps->length--;
	return true;
}

//删除第一个val的值
bool  DelVal(DPSQList ps, int val)
{
	int  i = Search(ps, val);
	if (i < 0)
		return false;

	return DelPos(ps, i);
}

//返回key的前驱下标,如果不存在返回-1
int  GetPrio(DPSQList  ps, int key)
{
	int i = Search(ps, key);
	if (i <= 0)
		return -1;

	return i-1;
}


//返回key的后继下标,如果不存在返回-1
int  GetNext(DPSQList  ps, int key)
{
	int i = Search(ps, key);
	if (i < 0 || i == ps->length - 1)
	{
		return -1;
	}
	return i +1;
}


//输出
void  Show(DPSQList  ps)
{
	assert(ps != NULL);
	if (ps == NULL)
	{
		return;
	}
	for (int i = 0; i < ps->length; i++)
	{
		printf("%d   ", ps->elem[i]);
	}
	printf("\n");
}

//清空数据
void  Clear(DPSQList ps)
{
	ps->length = 0;
}

//销毁整个内存
void   Destroy(DPSQList  ps)
{
	free(ps->elem);//1
	ps->elem = NULL;//2
	ps->length = 0;//3
	ps->listsize = 0;//4
	//ps = NULL;//5,无效的代码;error
}
