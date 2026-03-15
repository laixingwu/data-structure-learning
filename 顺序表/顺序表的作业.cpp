#if 0
#include "dsqlist.h"

bool    InsertX(DPSQList ps, int x)
{
	int i;
	for ( i = 0; i < ps->length; i++)
	{
		if (ps->elem[i] > x)
		{
			break;
		}
	}
	return Insert(ps,i,x);
}


int main()
{
	DSQList  ds;
	InitDSqlist(&ds);
	for (int i = 0; i < 6; i++)
	{
		Insert(&ds, i, i * 2);
	}
	Show(&ds);
	InsertX(&ds, 3);
	InsertX(&ds, -1);
	InsertX(&ds, 10);
	InsertX(&ds, 11);
	Show(&ds);

	return 0;
}
#endif


#if  0
#include "dsqlist.h"
#include <stdio.h>
int  DsqListCmp(DPSQList listA, DPSQList  listB)
{
	int i;
	for ( i = 0; i < listA->length && i < listB->length; i++)
	{
		if (listA->elem[i] != listB->elem[i])
		{
			return listA->elem[i] - listB->elem[i];
		}
	}
	return listA->length - listB->length;
}

int main()
{
	DSQList  ds1;
	DSQList  ds2;
	InitDSqlist(&ds1);
	InitDSqlist(&ds2);
	for (int i = 0; i < 6; i++)
	{
		Insert(&ds1, i, i);
	}
	Show(&ds1);

	for (int i = 0; i < 6; i++)
	{
		Insert(&ds2, i, i);
	}
	Show(&ds2);

	printf("%d   \n", DsqListCmp(&ds1, &ds2));

	return 0;
}
#endif


#include "dsqlist.h"
#include  <stdio.h>

//ÄæÖÃË³Ðò±í
void  Rerverse(DPSQList ps)
{
	int tmp;
	for (int i = 0, j = ps->length - 1; i < j; i++, j--)
	{
		tmp = ps->elem[i];
		ps->elem[i] = ps->elem[j];
		ps->elem[j] = tmp;
	}
}
int  main()
{
	DSQList  ds;
	InitDSqlist(&ds);
	for (int i = 0; i < 10; i++)
	{
		Insert(&ds, i, i);
	}
	//int index = GetNext(&ds, 5);
	//printf("index=%d\n", index);
	Show(&ds);

	Rerverse(&ds);
	Show(&ds);
	return 0;
}