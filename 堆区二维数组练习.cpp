/*
1. ������ά������ϰ�������װ������
a) �ڶ�������ռ䣬int a[3][4]
b) ͨ��ѭ����ÿһ��Ԫ�ظ�ֵ���Լ���ӡÿ��Ԫ�ص�ֵ
c) ʹ���꣬��Ҫ�ͷŶ����ռ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **a = (int**)malloc(3 * sizeof(int*));//����һά�ռ�
	if (a == NULL)
	{
		fprintf(stderr, "a allocate failed\n");
		return -1;
	}

	for (int i = 0; i < 3; i++)
	{
		a[i] = (int*)malloc(4 * sizeof(int));//�����ά�ռ�
		if (a[i] == NULL)
		{
			fprintf(stderr, "a allocate failed\n");
			goto End;
			return -1;
		}
	}

	for (int i = 0; i < 3; i++)//��ֵ
	{
		for (int j = 0; j < 4; ++j)
		{
			a[i][j] = 2 * i + 3 * j;
		}
	}

	for (int i = 0; i < 3; i++)//��ӡ
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("a[%d][%d] = %d\n", i, j, a[i][j]);
		}
	}

End:
	for (int  i = 0; i < 3; i++)//�ͷſռ�
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
