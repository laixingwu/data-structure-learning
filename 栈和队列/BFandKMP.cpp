//在主串str的pos位置查找子串sub, 找到返回下标, 没有找到返回 - 1;

//BF(朴素查找算法)
//笔试重点题目(必考)
//算法思想
//相等则继续比较,不相等则回退;回退是i必须回退,i退到刚才位置的下一个(i-j+1),j退到0;
//利用子串是否遍历完成,来判断是否查找成功;(注意:不能利用主串来判断)

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
int BF(const  char* str, const char* sub, int pos)
{
	assert(str != NULL && sub != NULL);
	if (str == NULL || sub == NULL||pos<0||pos>strlen(str))
	{
		return -1;
	}
	int i = pos;
	int j = 0;
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	while (i < lenstr && j < lensub)
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1 ;//刚才位置的下一个
			j = 0;
		}
	}
	//利用子串是否遍历完成, 来判断是否查找成功; (注意:不能利用主串来判断)
	if (j >= lensub)
	{
		return  i - j;
	}
	else
	{
		return -1;
	}

}

static int* GetNext(const char* str)
{
	int len = strlen(str);
	int* next = (int*)malloc(sizeof(int) * len);
	next[0] = -1;//不能再退
	next[1] = 0;//j=1,k=0;

	int j = 1;
	int k = 0;
	while (j +1 < len)
	{
		if ((k==-1)||str[k] == str[j])
		{
			next[++j] = ++k;
			/*next[j + 1] = k + 1;
			j = j + 1;
			k = k + 1;
			*/
		}
		else
		{
			k = next[k];
		}
	}
	return next;
}

int KMP(const  char* str, const char* sub, int pos)
{
	assert(str != NULL && sub != NULL);
	if (str == NULL || sub == NULL || pos<0 || pos>strlen(str))
	{
		return -1;
	}
	int i = pos;
	int j = 0;
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	int* next = GetNext(sub);
	while (i < lenstr && j < lensub)
	{
		if ((j==-1)||str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			//i 不回退
			j = next[j];
		}
	}
	free(next);
	//利用子串是否遍历完成, 来判断是否查找成功; (注意:不能利用主串来判断)
	if (j >= lensub)
	{
		return  i - j;
	}
	else
	{
		return -1;
	}

}


#if  0
int main()
{
	const  char* str1 = "ababcabcdabcde";
	const  char* str2 = "abcd";


	//printf("%d  ", BF(str1, str2, 0));
	//printf("%d  ", BF(str1, str2, 6));
	//printf("%d  ", BF(str1, str2, 10));
	printf("%d  ", KMP(str1, str2, 0));
	printf("%d  ", KMP(str1, str2, 6));
	printf("%d  ", KMP(str1, str2, 10));
	return 0;
}
#endif

