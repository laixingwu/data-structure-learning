#include "list.h"
#include <assert.h>
#include <stdio.h>

bool  IsCirlce(List plist)
{
	assert(plist != NULL);
	if (plist == NULL||plist->next==NULL)
		return false;

	Node* p = plist->next;//慢指针,一次走一步
	Node* q = plist->next->next;//快指针,一次走两步

	while (q != NULL && q->next!=NULL)
	{
		if (p == q)
		{
			break;
		}
		p = p->next;
		q = q->next->next;
	}

	if (q == NULL || q->next == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}


}

#if  0
int main()
{
	Node head;
	InitList(&head);
	for (int i = 0; i < 10; i++)
	{
		Insert_tail(&head, i);
	}
	Show(&head);

	if (IsCirlce(&head))
	{
		printf("该链表有环!\n");
	}
	else
	{
		printf("该链表没有环!\n");
	}

	Node* q = Search(&head, 3);//链表的某一个节点(数据域为3)
	Node* s = Search(&head, 9);//尾巴节点

	s->next = q;//构造环;

	if (IsCirlce(&head))
	{
		printf("该链表有环!\n");
	}
	else
	{
		printf("该链表没有环!\n");
	}

	return 0;
}
#endif