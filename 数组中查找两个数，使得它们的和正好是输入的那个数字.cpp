/*
* 输入一个已经按升序排序过的数组和一个数字
* 在数组中查找两个数，使得它们的和正好是输入的那个数字
* 如果有多对数字的和等于输入的数字，输出任意一对即可
* 例如输入数组：1,2,4,7,11,15 和 数字15，由于 4+11=15，所以输出4和11
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
