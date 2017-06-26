/*
* 输入一个字符串，输出其中第一次出现的不重复的字符
* 例如: 输入 aabccdeff 则输出 b
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main02(void)
{
	char *p = "aaaaabbbccdeff";
	int len = strlen(p);
	for (int i = 0; i < len;)
	{
		if (p[i] == p[i + 1])
		{
			int num = 2;
			for (int j = i + 2; ; j++, num++)
			{
				if (p[i] != p[j])
					break;
			}
			i += num;
		}
		else
		{
			printf("%c\n", p[i]);
			break;
		}
	}
	printf("Compelete\n");
	return 0;
}

