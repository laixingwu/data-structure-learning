#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include  "prio.h"

int Priority(char opera, bool InStack)
{
	int prio = OPERA_PRIO_ERR;
	if (InStack)
	{
		switch (opera)
		{
		case '+':
			prio = OPERA_PRIO_PLUS_IN;
			break;
		case '-':
			prio = OPERA_PRIO_MINUS_IN;
			break;
		case '*':
			prio = OPERA_PRIO_MULTIPLY_IN;
			break;
		case '/':
			prio = OPERA_PRIO_DIVISION_IN;
			break;
		case '(':
			prio = OPERA_PRIO_LEFT_BRACKETS_IN;
			break;
		default:
			prio = OPERA_PRIO_ERR;
			break;
		}
	}
	else
	{
		switch (opera)
		{
		case '+':
			prio = OPERA_PRIO_PLUS_OUT;
			break;
		case '-':
			prio = OPERA_PRIO_MINUS_OUT;
			break;
		case '*':
			prio = OPERA_PRIO_MULTIPLY_OUT;
			break;
		case '/':
			prio = OPERA_PRIO_DIVISION_OUT;
			break;
		case '(':
			prio = OPERA_PRIO_LEFT_BRACKETS_OUT;
			break;
		case ')':
			prio = OPERA_PRIO_RIGHT_BRACKETS_OUT;
			break;
		default:
			prio = OPERA_PRIO_ERR;
			break;
		}
	}
	return prio;
}

void MidtoLast(char* laststr, const char* midstr)
{
	int len = strlen(midstr);
	char* stack = (char*)malloc(len * sizeof(char));
	assert(stack != NULL);

	int top = 0;//栈顶指针,当前可以存放数据的下标;
	int i = 0;
	int prioOut = 0;//栈外符号优先级的数字;
	int prioIn = 0;//栈内符号优先级数字;
	while (*midstr != '\0')
	{
		if (isdigit(*midstr))
		{
			laststr[i++] = *midstr++;
		}
		else
		{
			if (top == 0)//栈空
			{
				stack[top++] = *midstr++;
			}
			else
			{
				prioIn=Priority(stack[top-1],true);//得到栈内符号的优先级数字;
				prioOut=Priority(*midstr,false);//得到栈外符号的优先级数字;
				if (prioOut < prioIn)//进栈
				{
					stack[top++] = *midstr++;
				}
				else if (prioOut > prioIn)//出栈
				{
					laststr[i++] = stack[--top];
				}
				else//左右括号匹配,直接删除
				{
					midstr++;
					top--;
				}
			}
		}
	}
	while (top > 0)
	{
		laststr[i++] = stack[--top];
	}

	laststr[i] ='\0' ;
	free(stack);
}
int main()
{
	const char* midstr = "3+4*2-2/(1+1)+5";
	char laststr[100];

	MidtoLast(laststr, midstr);
	printf("%s  \n", laststr);
	return 0;
}