/*
* ����һ���ַ�����������е�һ�γ��ֵĲ��ظ����ַ�
* ����: ���� aabccdeff ����� b
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

