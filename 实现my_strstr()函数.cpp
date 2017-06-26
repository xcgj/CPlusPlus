/*
实现my_strstr()函数，功能和strstr()函数一样。
a. 函数中不使用任何操作字符串的函数(如：strcpy、strcmp等)
b. 函数中的任何地方不使用下标。

功能：在字符串haystack中查找字符串needle出现的位置
参数：
haystack：源字符串首地址
needle：匹配字符串首地址
返回值：
成功：返回第一次出现的needle地址
失败：NULL

char *my_strstr(const char *haystack, const char *needle);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *my_strstr(const char *haystack, const char *needle)
{
	const char *temp = haystack;		//辅助指针

	int h_len = 0;						//原始字符串长度
	for (; *(temp + h_len); h_len++);	//len的终值是\0所在的下标位置，是字符串长度
	int n_len = 0;						//匹配字符串长度
	for (; *(needle + n_len); n_len++);	//len的终值是\0所在的下标位置，是字符串长度

	int i = 0;
	for (; i < h_len; i++)
		if (*(temp + i) == *(needle))	//匹配到第一个字符
		{
			int j = 0;
			int flag = 1;				//标记符
			const char *ttemp = temp + i;	//辅助指针
			for (; j < n_len; j++)		//验证后续字符的匹配
			{
				if (*(ttemp + j) != *(needle + j))//匹配失败跳出循环
				{
					flag = 0;
					break;
				}
			}
			if (flag)					//匹配成功，跳出循环
				return (char*)ttemp;
		}
	return NULL;
}

int main(void)
{
	const char *a = "abcdefghijklmn";
	const char *b = "ghia";
	char *p = my_strstr(a, b);
	printf("%p\n", p);
	return 0;
}