#include "stack.h"
#include <stdio.h>
#include <assert.h>

bool  IsBracketMatching(const char* str)
{
	assert(str != NULL);
	if (str == NULL)
		return false;

	Stack s;
	InitStack(&s);
	int oper;//±£´æÕ»¶¥µÄ·ûºÅ;

	while (*str != '\0')
	{
		if (*str == '('   || *str == '['   || *str == '{')
		{
			Push(&s, *str);
		}
		else  if(*str==')')
		{
			if (IsEmpty(&s))
			{
				return false;
			}
			Pop(&s, &oper);
			if (oper != '(')
			{
				return false;
			}
		}
		else if (*str == ']')
		{
			if (IsEmpty(&s))
			{
				return false;
			}
			Pop(&s, &oper);
			if (oper != '[')
			{
				return false;
			}
		}
		else if (*str == '}')
		{
			if (IsEmpty(&s))
			{
				return false;
			}
			Pop(&s, &oper);
			if (oper != '{')
			{
				return false;
			}
		}
		str++;
	}
	if (!IsEmpty(&s))
	{
		return false;
	}

	return true;
}
#if  0
int main()
{
	if (IsBracketMatching("(3+4)*3)+2*5-3"))
	{
		printf("À¨ºÅÆ¥Åä!\n");
	}
	else
	{
		printf("À¨ºÅ²»Æ¥Åä!\n");
	}

	return 0;
}
#endif
