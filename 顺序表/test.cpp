#if  0
#include <stdio.h>

#include "sqlist.h"

int main()
{
	int a = 10;
	int b = 30;
	printf("%d  ", Max(a, b));

	return 0;
}
#endif

#if 0
#include "sqlist.h"
#include <stdio.h>

int main()
{
	SQList  sq;
	InitSqlist(&sq);
	//Insert(&sq, 0, 100);
	//Show(&sq);
	for (int i = -1; i < 20; i++)
	{
		Insert(&sq, i, i);
	}
	Show(&sq);

	int i = Search(&sq, 5);
	if (i >= 0)
	{
		printf("该值位于%d号下标\n", i);
	}
	else
	{
		printf("没有找到该值!\n");
	}
	int index;
	for (int i = -1; i < 20; i++)
	{
		index = Search(&sq, i);
		if (index >= 0)
		{
			printf("%d位于%d号下标\n", i,index);
		}
		else
		{
			printf("没有找到该值!\n");
		}
	}
	DelPos(&sq, 9);
	Show(&sq);
	DelVal(&sq, 5);
	Show(&sq);
	Clear(&sq);
	Show(&sq);
	return 0;
}
#endif


#if 0
#include "dsqlist.h"
int main()
{
	DSQList   ds;
	InitDSqlist(&ds);
	
	//for (int i = -1; i < 21; i++)
	//{
	//	Insert(&ds, i, i);
	//}
	//
	Insert(&ds, 0, 10);
	Show(&ds);
	DelPos(&ds, 100);
	Show(&ds);
	DelVal(&ds, 10);
	Show(&ds);
	Destroy(&ds);

	return 0;
}
#endif
