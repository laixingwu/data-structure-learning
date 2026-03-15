#pragma once

//顺序表的特点:
//插入数据的时间复杂度是O(n),如果是尾插时间复杂度是O(1);
//删除数据的时间复杂度是O(n), 如果是尾删时间复杂度是O(1);
//通过下标访问数据的时间复杂度是O(1);


//顺序表逻辑上相邻的元素物理上也相邻,所以插入和删除操作需要移动大量元素;
//存储密度大(高),每个结点只存储数据元素(对比链表);
//随机访问:顺序表是一种支持随机存取的存储结构,根据起始地址加上元素的序号,可以在O(1)时间内找到指定的元素,这就是随机存取的概念;

#define  INIT_SIZE  10
typedef  struct  DSQList
{
	int* elem;//动态内存的地址
	int  length;//有效数据的个数
	int  listsize;//总容量
}DSQList,*DPSQList;

//初始化
void   InitDSqlist(DPSQList  ps);

//插入数据,在ps顺序表的pos位置插入val;
bool   Insert(DPSQList ps, int pos, int val);

//判空
bool   IsEmpyt(DPSQList ps);

//在ps中查找第一个key值,找到返回下标,没有找到返回-1
int   Search(DPSQList   ps, int key);


//删除pos位置的值
bool   DelPos(DPSQList ps, int pos);

//删除第一个val的值
bool  DelVal(DPSQList ps, int val);

//返回key的前驱下标,如果不存在返回-1
int  GetPrio(DPSQList  ps, int key);


//返回key的后继下标,如果不存在返回-1
int  GetNext(DPSQList  ps, int key);


//输出
void  Show(DPSQList  ps);

//清空数据
void  Clear(DPSQList ps);

//销毁整个内存
void   Destroy(DPSQList  ps);
