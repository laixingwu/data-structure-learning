
#if  0
#include "list.h"
#include <stdio.h>


int main()
{
	Node  head;
	InitList(&head);
	//int len = Getlength(&head);
	//printf("len=%d\n", len);
	for (int i = 0; i < 10; i++)
	{
		Insert_head(&head, i);
		//Insert_tail(&head, i);
	}
	//Insert_tail(&head, 1000);
	// len = Getlength(&head);
	//printf("len=%d\n", len);
	//Show(&head);
	//Node *p=Search(&head, 5);
	/*if (p != NULL)
	{
		printf("%d\n", p->data);
	}
	else
	{
		printf("没有找到!\n");
	}
	DelVal(&head, 5);
	Show(&head);
	Insert(&head, 0, 100);*/
	/*Show(&head);

	DelPos(&head, 10);
	Show(&head);
	 
	Destroy(&head);*/

	Show(&head);
	Reverse(&head);
	printf("逆置链表之后为:\n");
	Show(&head);
	
	return 0;
}
#endif



#if  0
#include "clist.h"
#include <stdio.h>
int   main()
{
	CNode  head;
	InitCList(&head);
	for (int i = 0; i < 10; i++)
	{
		//Insert_head(&head, i);
		Insert_tail(&head, i);
	}
	Show(&head);

	Insert(&head, 11, 100);
	Show(&head);

	CNode *p=Search(&head, 12);
	if (p != NULL)
	{
		printf("%d\n", p->data);
	}
	else
	{
		printf("没有找到!\n");
	}

	DelVal(&head, 2);
	DelVal(&head, 0);
	Show(&head);
	DelPos(&head, 0);
	Show(&head);
	Destroy(&head);
	return 0;
}
#endif


#if  0
#include "dlist.h"
#include <stdio.h>
int main()
{
	DNode head;
	InitList(&head);
	for (int i = 0; i < 10; i++)
	{
		//Insert_head(&head,i);
		Insert_tail(&head, i);
	}
	Show(&head);
	int len = Getlength(&head);
	printf("len=%d\n", len);
	DelVal(&head, 9);

	Insert(&head, 0, 100);

	DelPos(&head, 9);
	Show(&head);
	Destroy(&head);

	return 0;
}
#endif


#if  0
#include "slist.h"
#include <stdio.h>
int main()
{
	SLinkList s;
	//printf("%d  ", sizeof(s));
	InitList(s);

	for (int i = 0; i < 10; i++)
	{
		//Insert_head(s, i);
		Insert_tail(s, i);
	}
	int len = Getlength(s);
	printf("len=%d  ", len);
	Show(s);//

	DelVal(s, 2);
	Show(s);
	return  0;
}
#endif
