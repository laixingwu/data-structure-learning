#include "list.h"
#include <stdio.h>
#include <stdlib.h>
//删除倒数第K个点
//将k转化为顺数的len-k+1个点
bool   DeleteK1(List plist, int k)
{
	int len = Getlength(plist);
	if (plist == NULL||k<=0||k>len)
	{
		return false;
	}
	k = len - k + 1;//顺数第k个点
	Node* p =plist;
	for (int i = 0; i < k-1; i++)
	{
		p = p->next;
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);

	return true;
}


//方法二:
//算法思想:快慢指针
//用两个指针,p,q先指向plist,p先走k步, 然后p,q一起走;
//当p->next==NULL,q就是要删除的节点的前驱;
bool  DeleteK(List plist, int k)
{
	if (plist == NULL || k <= 0 || k > Getlength(plist))
	{
		return false;
	}
	Node* p = plist;
	Node* q = plist;
	for (int i = 0; i < k; i++)//p先走k步
	{
		p = p->next;
	}

	while (p->next != NULL)//p,q一起走
	{
		p = p->next;
		q = q->next;
	}
	//删除q后面的节点
	p = q->next;
	q->next = p->next;
	free(p);

	return true;
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
	DeleteK(&head, -2);
	DeleteK(&head, 0);
	Show(&head);
	DeleteK(&head, 5);
	Show(&head);

	return 0;
}
#endif