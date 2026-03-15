#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "lqueue.h"
//排序
// 从小到大(默认)
//1.算法描述  2.代码实现  3.效率分析(时间复杂度,空间复杂度,稳定性)
//稳定性:针对当前关键字相同的数据(相同的数字),排序前如果A在A'的前面,排完序之后还能保证A在A'的前面,则算法稳定,否则算法不稳定
//稳定性:主要看有没有跳跃式的交换数据;


//八个排序
//1.插入排序(简单插入排序或者直接插入排序)
// 算法描述:从当前位置开始,从后往前找比当前数字小的,插入到这个小的数字的后面;
// 在找的过程中,如果发现一个比当前数字大,同时将这个数字往后挪动;
// 重点:从后往前,为什么?
// 特点:数据越有序越快,完全有序O(n)


//2.希尔排序
// 理论基础:直接插入排序
// 算法描述:间隔式分组,利用直接插入排序让组内有序; 然后缩小分组,再次排序,直到数组组数为1;
// 
//3.冒泡排序:两两比较(相邻),大的往后走
//4.快速排序(必考) : 找到一个基准(第一个数据),1.从后往前找比基准小的数据往前移动;
// 2.从前往后找比基准大的数据往后移动3.重复1,2直到找到基准的最终位置(一次划分)
// 多次调用一次划分;
// 快速排序的缺点:越有序越慢;  (完全有序退化成选择排序)
//5.选择排序:每次都从待排序中选出一个最小的和待排序中的第一个数据交换;(待排序,一定注意"待")
//6.堆排序
//7.归并排序:将两段有序的合并成为一段有序的数据,直到所有的数据都有序;
// 把两段有序的归并为一段更大的有序的,也成为2路归并
//8.基数排序(桶排序)
//第"9"个:链表排序:STL自带的list为双向链表




void InsertSort(int* arr, int len)//O(n^2),O(1),稳定的
{
	int tmp;
	for (int i = 1; i < len; i++)//i是当前要处理的数字的下标
	{
		tmp = arr[i];
		int j;
		for ( j = i - 1; j >= 0; j--)//从后往前找位置,找比当前数字小的,同时移动数据
		{
			if (arr[j] > tmp)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				//arr[j + 1] = tmp;
				break;
			}
		}
		arr[j + 1] = tmp;
	}
}


void  SelectSort(int* arr, int len)//O(n^2),O(1),不稳定
{
	int  tmp;
	int  minIndex;//最小值的下标
	for (int i = 0; i < len - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)//最小值和待排序的第一个如果是一个,我们不交换
		{
			tmp = arr[minIndex];
			arr[minIndex] = arr[i];
			arr[i] = tmp;
		}	
	}
}
//快速排序的一次划分
int  Partition(int* arr, int low, int high)//O(n),一次划分
{
	int tmp = arr[low];
	while (low < high)
	{
		//从后往前找比基准小的数字,往前移动
		while (low<high  &&  arr[high] > tmp)
		{
			high--;
		}
		if (low < high)
		{
			arr[low] = arr[high];
		}

		//从前往后找比基准大的数据,往后移动
		while (low < high && arr[low] <= tmp)
		{
			low++;
		}
		if (low < high)
		{
			arr[high] = arr[low];
		}
	}

	arr[low] = tmp;
	return low;
}

void     BubbleSort(int* arr, int len)//O(n^2),O(1),稳定
{
	int tmp;
	for (int i = 0; i < len-1;i++)//趟数,len个数字需要len-1趟
	{
		for (int j = 0; j +1< len-i; j++)//j+1必须有
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//void  QuickSort(int* arr, int len)
//{
//	int par = Partition(arr, 0, len - 1);
//	if (0 < par - 1)//左边的数据超过一个
//	{
//		QuickSort(arr,???);//矛盾
//	}
//	if//右边的数据超过一个
//	{
//		QuickSort();
//	}
//}

void Quick(int* arr, int low, int high)//O(nlogn),O(logn),不稳定
{
	int par = Partition(arr, low, high);//par是基准应该放的位置的下标
	if (low<par-1)//左边超过一个数字
	{
		Quick(arr, low, par - 1);
	}
	if (par+1<high)//右边超过一个数字
	{
		Quick(arr, par + 1, high);
	}
}
void QuickSort(int* arr, int len)
{
	Quick(arr, 0, len - 1);
}

void  Show(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//一趟希尔排序;//gap为组数(间隔)
static  void  Shell(int* arr, int len, int gap)//gap为组数(间隔)
{
	int  tmp;
	for (int i = gap; i < len; i++)//i是当前要处理的数字的下标???
	{
		tmp = arr[i];
		int j;
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (arr[j] > tmp)
			{
				arr[j + gap] = arr[j];
			}
			else
			{	
				//arr[j + gap] = tmp;
				break;
			}
		}
		arr[j + gap] = tmp;
	}
}

void  ShellSort(int* arr, int len)//O(n^1.3~n^1.5),O(1),不稳定
{
	int drr[] = {5,3,1};//分组数,最后一个一定为1
	for (int i = 0; i < sizeof(drr) / sizeof(drr[0]); i++)
	{
		Shell(arr, len, drr[i]);//一趟希尔排序
	}
}

void  HeapAdjust(int* arr, int start, int end)
{
	int tmp = arr[start];
	for (int i = 2 * start + 1; i <= end;i=2*i+1)
	{
		if (i < end && arr[i] < arr[i + 1])//如果有右孩子,并且左孩子的值小于右孩子
		{
			i++;
		}//i一定是左右孩子的最大值
		if (arr[i] > tmp)
		{
			arr[start] = arr[i];
			start = i;
		}
		else
		{
			//arr[start] = tmp;
			break;
		}
	}
	arr[start] = tmp;
}


//堆排序
void  HeapSort(int* arr, int len)//O(nlogn),O(1),不稳定
{
	//第一次建立大根堆(从后往前,多次调整)(4,3,2,1,0这些子树)
	for (int i = (len-1-1)/2; i >= 0; i--)//O(n),数学证明
	{
		HeapAdjust(arr, i, len - 1);
	}

	int tmp;
	//每次将根和待排序的最后一个交换,然后再次调整  (注意:待排序的"待");
	for (int i = 0; i < len - 1; i++)//O(nlogn)
	{
		//交换
		tmp = arr[0];
		arr[0] = arr[len - 1 - i];
		arr[len-1-i] = tmp;

		//再次调整
		HeapAdjust(arr,0,len-1-i-1 );
	}
}
//一次归并
//gap:归并段的长度
static   void  Merge(int* arr, int len, int gap)//O(n),O(n)
{
	int  low1=0;//第一个归并段的起始下标
	int high1=low1+gap-1; //第一个归并段的结束下标
	int low2=high1+1;   //第二个归并段的起始下标
	int high2=low2+gap<len  ? low2+gap-1:len-1; //第二个归并段的结束下标

	int* brr = (int*)malloc(len * sizeof(int));//存放归并好的数据
	assert(brr != NULL);
	int  i = 0;//brr的下标
	//有两个归并段
	while (low2 < len)
	{
		//两个归并段都有数据,需要比较l1和l2
		while (low1 <= high1 && low2 <= high2)
		{
			if (arr[low1] <= arr[low2])
			{
				brr[i++] = arr[low1++];
			}
			else
			{
				brr[i++] = arr[low2++];
			}
		}

		//一个归并段的数据已经完成了,另一个还有数据
		while (low1 <= high1)
		{
			brr[i++] = arr[low1++];
		}
		while (low2 <= high2)
		{
			brr[i++] = arr[low2++];
		}

		//下两个归并段
		low1 = high2 + 1;
		high1 = low1 + gap - 1;
		low2 = high1 + 1;
		high2 =   low2 + gap < len   ?      low2 + gap - 1    : len - 1;
	}


	//只有一个归并段
	while (low1<len)
	{
		brr[i++] = arr[low1++];
	}
	
	//将归并好的数据拷贝到arr中;
	for (i = 0; i < len; i++)
	{
		arr[i] = brr[i];
	}
	free(brr);
}


//归并排序
void  MergeSort(int* arr, int len)//O(nlogn),O(n),稳定
{
	for (int i = 1; i < len; i*=2)
	{
		Merge(arr, len, i);//一趟归并
	}
}
//获取最大数字的位数
static  int GetFigur(int* arr, int len)
{
	int  max = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	//max已经是最大值了;
	
	//丢弃个位
	int  count = 0;
	while (max != 0)
	{
		count++;
		max /= 10;
	}
	return count;
}

//获取十进制整数右数第figur位的数据,figur从0开始
//例如(123,0)->3,(123,1)->2,(123,2)->1,(123,3)->0
static  int  GetNum(int n, int figur)
{
	for (int i = 0; i < figur; i++)
	{
		n /= 10;
	}
	return n % 10;
}

void RadixSort(int* arr, int len)//O(d*n),O(n),稳定
{
	//定义10个队列
	HNode  queArr[10];
	for (int i = 0; i < 10; i++)
	{
		InitQueue(&queArr[i]);
	}

	//得到最大数字的位数,确定进队和出队的趟数
	int  count = GetFigur(arr, len);

	int index;//队列的下标
	for (int i = 0; i < count; i++)//i:进入几次桶的遍历次数  i:处理每个数字从右往左的第i个数字
	{
		//入队
		for (int j = 0; j < len; j++)//遍历数组入队
		{
			index = GetNum(arr[j], i);//index保存arr[j]进入队列的下标;
			Push(&queArr[index], arr[j]);
		}

		//依次出队
		int j = 0;//arr的下标
		for (int k = 0; k < 10; k++)
		{
			while (!IsEmpty(&queArr[k]))
			{
				Pop(&queArr[k], &arr[j++]);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		Destroy(&queArr[i]);
	}
}

int main()
{
	//int arr[] = { 6,0,15,7,8,9,11,20,40,35 };
	//int arr[] = { 20,33,21,54,17,-16,30,18,19};//error,桶排序不能处理负数
	int arr[] = { 20,33,21,54,17,16,30,18,19 };
	Show(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
    //BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	//MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	RadixSort(arr, sizeof(arr) / sizeof(arr[0]));

	Show(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}

