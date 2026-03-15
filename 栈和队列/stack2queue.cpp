//#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include "queue.h"

//利用两个栈模拟入队
//栈1,用来存放刚入队的数据;
//栈2,用来出队,栈空则把s1中的数据出到s2中,栈不空,直接从s2出栈

#if  0
bool  QueuePush(Stack* s1, Stack* s2, int val)
{
	assert(s1 != NULL && s2 != NULL);
	if (s1 == NULL || s2 == NULL)
		return false;
	return Push(s1, val);
}

//利用两个栈模拟出队
bool  QueuePop(Stack* s1, Stack* s2, int* rtval)
{
	assert(s1 != NULL && s2 != NULL);
	if (s1 == NULL || s2 == NULL)
		return false;

	int  tmp;
	if (IsEmpty(s2))//所有的数据都从s2出
	{
		while (Pop(s1, &tmp))//将s1的数据移动到s2中;
		{
			Push(s2, tmp);
		}
	}

	return  Pop(s2, rtval);
}

int  main()
{
	Stack s1;
	Stack s2;
	InitStack(&s1);
	InitStack(&s2);
	int  tmp;
	for (int i = 0; i < 10; i++)
	{
		QueuePush(&s1, &s2, i);
	}

	for (int i = 0; i < 10; i++)
	{
		if (QueuePop(&s1, &s2, &tmp))
		{
			printf("%d  ", tmp);
		}
	}
	Destroy(&s1);
	Destroy(&s2);

	return 0;
}
#endif


//利用两个队列模拟入栈
//队列1,用来存放入栈的数据;
//队列2,需要出站时的中转站
bool  StackPush(PSqQueue q1, PSqQueue q2, int val)
{
	assert(q1 != NULL && q2 != NULL);
	if (q1 == NULL || q2 == NULL)
		return false;

	return Push(q1, val);
}

//出栈
//出q1的最后一个数据,其他数据暂时存放在q2中;
//出栈后再将q2的数据必须移动到q1中;
bool   StackPop(PSqQueue q1, PSqQueue q2, int* rtval)
{
	assert(q1 != NULL && q2 != NULL);
	if (q1 == NULL || q2 == NULL)
		return false;

	int  tmp;
	if (IsEmpty(q1))
	{
		return false;
	}

	while (Pop(q1, &tmp))//出q1的最后数据,其他数据存放在q2中
	{
		if (!IsEmpty(q1))//最后一个数据不保存在q2中
		{
			Push(q2, tmp);
		}
	}
	*rtval = tmp;

	while (Pop(q2, &tmp))//q2只是暂存,所有数据必须移动到q2中
	{
		Push(q1, tmp);
	}

	return  true;
}

#if  0

int  main()
{
	SqQueue q1;
	SqQueue  q2;
	InitQueue(&q1);
	InitQueue(&q2);
	int  tmp;
	for (int i = 0; i < 10; i++)
	{
		StackPush(&q1, &q2, i);
	}

	for (int i = 0; i < 10; i++)
	{
		if (StackPop(&q1, &q2, &tmp))
		{
			printf("%d  ", tmp);
		}
	}
	Destroy(&q1);
	Destroy(&q2);

	return 0;
}
#endif