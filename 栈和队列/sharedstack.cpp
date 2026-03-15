#include "sharedstack.h"
#include <assert.h>
#include <stdio.h>
//初始化
void  InitSharedStack(PSharedStack ps)
{
	assert(ps != NULL);
	if (ps == NULL)
		return;

	ps->top1 = 0;
	ps->top2 = STACK_SIZE - 1;
}

static  bool  IsFul(PSharedStack ps)
{
	return   ps->top1 > ps->top2;
}


//入栈
//no标记从1栈入还是从2栈入
bool  Push(PSharedStack ps, int val, int no)
{
	assert(ps != NULL);
	if (ps == NULL)
		return false;

	if (IsFul(ps)||no<1||no>2)
	{
		return false;
	}

	if (no == 1)
	{
		ps->elem[ps->top1++] = val;
	}
	else
	{
		ps->elem[ps->top2--] = val;
	}
	return true;
}

//出栈
bool  Pop(PSharedStack ps, int* rtval, int no)
{
	assert(ps != NULL);
	if (ps == NULL)
		return false;

	if (no == 1 && !IsEmpty1(ps))
	{
		*rtval = ps->elem[--ps->top1];
		return true;
	}
	else if (no == 2 && !IsEmpty2(ps))
	{
		*rtval = ps->elem[++ps->top2];
		return true;
	}

	return false;
}

//判空
bool IsEmpty1(PSharedStack ps)//判断1栈是否为空栈
{
	assert(ps != NULL);
	if (ps == NULL)
		return false;

	return ps->top1 == 0;
}
bool IsEmpty2(PSharedStack ps)//判断2栈是否为空栈
{
	assert(ps != NULL);
	if (ps == NULL)
		return false;

	return ps->top2 == STACK_SIZE - 1;
}

#if  0
int main()
{
	SharedStack s;
	InitSharedStack(&s);

	for (int i = 0; i < 6; i++)
	{
		Push(&s, i, 1);//0-5   ,6个
	}
	for (int i = 10; i < 16; i++)
	{
		Push(&s, i, 2);//10-15   4个; //10,11,12,13
	}

	int tmp;
	while (!IsEmpty1(&s))
	{
		Pop(&s, &tmp, 1);
		printf("%d ", tmp);
	}//5,4,3,2,1,0

	printf("\n");
	while (!IsEmpty2(&s))
	{
		Pop(&s, &tmp, 2);
		printf("%d  ", tmp);
	}//13,12,11,10

	return 0;
}
#endif
