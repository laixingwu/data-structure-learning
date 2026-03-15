//哈希表:
//除留余数法+链式地址法
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define  m  13//m个单链表,哈希表的长度
typedef  struct DateType
{
	int key;//关键字项
	//InfoType  otherinfo;//其他数据项
}DataType;//数据类型

typedef struct Node
{
	DataType  data;//数据域;
	struct Node* next;//指向下一个节点
}Node;//链式地址法中的链表节点

typedef struct
{
	Node * next;//链表的地址
}HashTable[m];//哈希表

//初始化哈希表
void  InitHashTable(HashTable ht)
{
	assert(ht != NULL);
	if (ht == NULL)
	{
		return;
	}
	for (int i = 0; i < m; i++)//将所有的链表都置空
	{
		ht[i].next = NULL;
	}
}

//计算key的哈希值,哈希函数为H(key)=key%m
static  int H(int key)
{
	return key % m;
}

//在哈希表中查找key,找到返回节点地址,失败返回NULL;
Node* Search(const HashTable ht, int key)
{
	int hi = H(key);
	for (Node* p = ht[hi].next; p != NULL; p = p->next)
	{
		if (p->data.key == key)
		{
			return p;
		}
	}
	return NULL;
}

//将key插入到哈希表ht中,成功返回true,失败返回false;
bool  Insert(HashTable ht, int key)
{
	int  hi = H(key);
	if (Search(ht, key) != NULL)//key已经存在
	{
		return  false;
	}
	//插入key
	Node* p = (Node*)malloc(sizeof(Node));
	assert(p != NULL);
	p->data.key = key;
	//头插
	p->next = ht[hi].next;
	ht[hi].next = p;
	return true;
}

//从头到尾输出ht的所有的值
void  Show(HashTable ht)
{
	for (int i = 0; i < m; i++)
	{
		printf("哈希值为%d的有:", i);
		for (Node* p = ht[i].next; p != NULL; p = p->next)
		{
			printf("%d ", p->data.key);
		}
		printf("\n");
	}
}

#if 0
int  main()
{
	HashTable ht;
	InitHashTable(ht);

	int  arr[16] = { 3,5,7,1,2,9,28,25,6,11,10,15,17,23,34,19 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		Insert(ht, arr[i]);
	}
	Show(ht);
	return 0;
}
#endif
