#if  0
//哈希表:除留余数法+开地址法(线性探测)
#include <stdio.h>
#define m  16//哈希表的长度
#define p    13 // p<=m,为质数
#define  NONE  -1//当前哈希表为空
typedef  struct  Hash
{
	int  key;//关键字项;
	//InfoType  otherinfo;//其他数据项
}Hash,HashTable[m];

//初始化哈希表
void  InitHashTable(HashTable  ht)
{
	for (int i = 0; i < m; i++)
	{
		ht[i].key = NONE;
	}
}

static  int H(int key)
{
	return key % p;
}

//将key插入到哈希表ht中,成功返回true,失败返回false;
bool   Insert(HashTable ht, int key)
{
	int hi = H(key);//得到key的哈希值;
	//当前哈希表没有被使用,将key直接存储;
	if (ht[hi].key == NONE)
	{
		ht[hi].key = key;
		return true;
	}

	//else  在其他地方找合适的位置;使用线性探测法;
	else
	{
		for (int d = 1; d < m; d++)
		{
			int  newHi = (hi + d) % m;
			if (ht[newHi].key == key)//key已经存在,不再另外储存
			{
				return true;
			}
			else  if (ht[newHi].key == NONE)
			{
				ht[newHi].key = key;
				return true;
			}
		}
		return false;//存满,没有空位
	}
}

//在哈希表中查找key,找到返回下标,失败返回-1
int  Search(const  HashTable ht, int key)
{
	int hi = H(key);
	for (int i = 0; i < m; i++)
	{
		int newHi = (hi + i) % m;
		if (ht[newHi].key == key)
		{
			return newHi;
		}
		else if (ht[newHi].key == NONE)//没有找到
		{
			break;
		}
	}
	return -1;
}

//从头到尾输出ht的所有值
void  Show(HashTable ht)
{
	for (int i = 0; i < m; i++)
	{
		printf("%d ", ht[i].key);
	}
	printf("\n");
}

int main()
{
	HashTable ht;
	InitHashTable(ht);
	int  arr[16] = { 3,5,7,1,2,9,28,25,6,11,10,15,17,23,34,19 };
    
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		Insert(ht, arr[i]);
	}
	Show(ht);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d :%d \n", arr[i], Search(ht, arr[i]));
	}

	return 0;
}
#endif
