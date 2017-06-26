/*
1. 堆区二维数组练习（无需封装函数）
a) 在堆区申请空间，int a[3][4]
b) 通过循环给每一个元素赋值，以及打印每个元素的值
c) 使用完，需要释放堆区空间
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **a = (int**)malloc(3 * sizeof(int*));//申请一维空间
	if (a == NULL)
	{
		fprintf(stderr, "a allocate failed\n");
		return -1;
	}

	for (int i = 0; i < 3; i++)
	{
		a[i] = (int*)malloc(4 * sizeof(int));//申请二维空间
		if (a[i] == NULL)
		{
			fprintf(stderr, "a allocate failed\n");
			goto End;
			return -1;
		}
	}

	for (int i = 0; i < 3; i++)//赋值
	{
		for (int j = 0; j < 4; ++j)
		{
			a[i][j] = 2 * i + 3 * j;
		}
	}

	for (int i = 0; i < 3; i++)//打印
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("a[%d][%d] = %d\n", i, j, a[i][j]);
		}
	}

End:
	for (int  i = 0; i < 3; i++)//释放空间
	{
		if (a[i] != NULL)
		{
			free(a[i]);
			a[i] = NULL;
		}
	}
	if (a != NULL)
	{
		free(a);
		a = NULL;
	}
	printf("Compelete\n");
	return 0;
}
