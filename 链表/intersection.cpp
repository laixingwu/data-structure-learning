#include "list.h"
#include <stdio.h>

#if  0
//求入环的第一个点
//必须掌握
Node* FirstCircleNode(List plist)
{
	if (plist == NULL || plist->next == NULL)
	{
		return NULL;
	}
	Node* p = plist->next->next;//快指针
	Node* q = plist->next;//慢指针

	while (p != NULL &&p->next!=NULL &&p!=q)
	{
		p = p->next->next;
		q = q->next;
	}
	if (p == NULL || p->next == NULL)//没有环
	{
		return  NULL;
	}

	//快慢指针相遇了;
	Node* s = plist;//1
	while (s != q)
	{
		s = s->next;
		q = q->next;
	}
	return s;
}

int main()
{
	Node head;
	InitList(&head);
	for (int i = 0; i < 10; i++)
	{
		Insert_tail(&head, i);
	}
	Show(&head);

	Node* p = Search(&head, 9);
	p->next = Search(&head, 3);//形成环;3是入环的第一个点
	if ((p = FirstCircleNode(&head)) != NULL)
	{
		printf("入环的第一个节点是%d\n", p->data);
	}

	return 0;
}
#endif

//求两个链表的交点
//必须掌握
#if 0
#include <assert.h>
Node* FirstIntersection1(List plist1, List plist2)
{
	if (plist1 == NULL || plist2 == NULL)
	{
		return NULL;
	}

	int len1 = Getlength(plist1);
	int len2 = Getlength(plist2);
	Node* r = plist1->next;
	Node* s = plist2->next;
	while (len1 > len2)
	{
		r = r->next;
		len1--;
	}
	while (len2 > len1)
	{
		s = s->next;
		len2--;
	}

	while (r != NULL && s != NULL)
	{
		if (r == s)
		{
			break;
		}
		r = r->next;
		s = s->next;
	}

	if (r == s && r != NULL)
	{
		return r;
	}
	else
	{
		return NULL;
	}
}

//了解
Node* FirstIntersection(List plist1, List plist2)
{
	if (plist1 == NULL || plist2 == NULL)
	{
		return NULL;
	}
	Node* p = plist1;
	Node* q = plist2;
	while (p != q)
	{
		p = p == NULL ? plist2 : p->next;
		q = q == NULL ? plist1 : q->next;
	}
	return p;
}

int main()
{
	Node head1;
	Node head2;
	InitList(&head1);
	InitList(&head2);

	//构造没有交点的两条无环链表
	for (int i = 0; i < 10; i++)
	{
		Insert_tail(&head1, i);
		Insert_tail(&head2, i + 100);
	}
	Show(&head1);
	Show(&head2);

	Node* p = FirstIntersection(&head1, &head2);
	if (p == NULL)
	{
		printf("两条链表没有交点!\n");
	}
	else
	{
		printf("两个链表的交点为%d\n", p->data);
	}


	Node head3;
	Node head4;
	InitList(&head3);
	InitList(&head4);

	//构造没有交点的两条无环链表
	for (int i = 0; i < 10; i++)
	{
		Insert_tail(&head3, i);
	}
	Insert_tail(&head4, 20);
	Insert_tail(&head4, 21);
	Show(&head3);
	Show(&head4);

	Node* r;
	Node* s;
	r = Search(&head3, 3);
	s = Search(&head4, 21);
	assert(r != NULL && s != NULL && s->next == NULL);
	s->next = r;//3是两条链表的第一个交点

     p = FirstIntersection(&head3, &head4);
	if (p == NULL)
	{
		printf("两条链表没有交点!\n");
	}
	else
	{
		printf("两个链表的交点为%d\n", p->data);
	}


	return 0;
}
#endif