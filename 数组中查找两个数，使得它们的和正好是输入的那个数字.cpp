/*
* ����һ���Ѿ�������������������һ������
* �������в�����������ʹ�����ǵĺ�������������Ǹ�����
* ����ж�����ֵĺ͵�����������֣��������һ�Լ���
* �����������飺1,2,4,7,11,15 �� ����15������ 4+11=15���������4��11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01(void)
{
	int a[] = { 0,1,2,4,7,11,15 };
	int len = 6;
	int n = 15;
	int num = 0;
	for (int x = 0; x < len - 1; x++)
	{
		if (a[x] > n / 2)
			break;
		for (int j = x + 1; j < len; ++j)
		{
			num++;
			if (a[j] > n)
				break;
			if (a[x] + a[j] == n)
				printf("%d, %d\n", a[x], num);
		}
	}
	return 0;
}
