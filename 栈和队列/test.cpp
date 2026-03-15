#include <stdio.h>
//#include "stack.h"
//#include  "lstack.h"
//#include "queue.h"

//#include "lqueue.h"

#if  0
int main()
{
	HNode q;
	InitQueue(&q);
	//Push(&q, 100);
	for (int i = 0; i < 13; i++)
	{
		Push(&q, i);
	}
	int len = GetLength(&q);
	printf("len=%d\n", len);


	int tmp;
	GetTop(&q, &tmp);
	printf("%d\n", tmp);

	while (!IsEmpty(&q))
	{
		Pop(&q, &tmp);
		printf("%d  ", tmp);
	}
	 len = GetLength(&q);
	printf("len=%d\n", len);

	Destroy(&q);
	return 0;
}
#endif

#if  0
int  main()
{
	SqQueue  q;
	InitQueue(&q);
	for (int i = 0; i < 13; i++)
	{
		Push(&q, i);
	}

	int val;
	GetTop(&q, &val);
	//printf("%d\n", val);

	while (!IsEmpty(&q))
	{
		Pop(&q, &val);
		printf("%d\n", val);
	}
	Destroy(&q);

	return 0;
}
#endif

#if   0
int  main()
{
	LSNode s;
	InitStack(&s);

	for (int i = 0; i < 13; i++)
	{
		Push(&s, i);
	}

	int val;
	GetTop(&s, &val);
	printf("%d\n", val);

	int len = GetLength(&s);
	printf("len=%d  ", len);
	for (int i = 0; i < 20; i++)
	{
		if (Pop(&s, &val))
		{
			printf("%d  ", val);
		}
		else
		{
			break;
		}
	}

	 len = GetLength(&s);
	printf("len=%d  ", len);

	Destroy(&s);
	return 0;
}

#endif
#if  0
int main()
{
	Stack  s;
	InitStack(&s);

	for (int i = 0; i < 13; i++)
	{
		Push(&s, i);
	}

	int val;
	GetTop(&s, &val);
	printf("%d\n", val);
	int len = GetLength(&s);
	printf("len=%d\n", len);

	for (int i = 0; i < 20; i++)
	{
		if (Pop(&s, &val))
		{
			printf("%d  ", val);
		}
		else
		{
			break;
		}
	}
   len = GetLength(&s);
	printf("len=%d\n", len);
	Destroy(&s);
	return 0;
}
#endif