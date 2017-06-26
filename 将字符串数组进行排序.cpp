#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(char ** array1, int num1, char(*array2)[30], int num2, char *** myp3 /*out*/, int * num3);
int printBuf(char ** p3, int len3);
int free_buf(char *** p3, int len3);

int  main()
{
	int ret = 0;
	char * p1[] = { "aa", "ccccccc", "bbbbbb" };
	char buf2[][30] = { "111111", "3333333", "222222" };
	char ** p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);		//元素个数
	len2 = sizeof(buf2) / sizeof(buf2[0]);	//元素个数

	ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret < 0)
	{
		printf("err:%d\n", ret);
		return ret;
	}

	ret = printBuf(p3, len3);
	if (ret < 0)
	{
		printf("err:%d\n", ret);
		return ret;
	}

	ret = free_buf(&p3, len3);
	if (ret < 0)
	{
		printf("err:%d\n", ret);
		return ret;
	}

	return ret;
}

int printBuf(char ** p3, int len3)
{
	int res = 0;
	if (p3 == NULL || *p3 == NULL)
	{
		res = -1;
		fprintf(stderr, "func printBuf NULL pointer\n");
		return res;
	}
	int i = 0;
	for (; i < len3; i++)
		printf("p[%d] = %s\n", i, p3[i]);
	return res;
}

int free_buf(char *** p3, int len3)
{
	int res = 0;
	if (p3 == NULL || *p3 == NULL)
	{
		res = -1;
		fprintf(stderr, "func free_buf NULL pointer\n");
		return res;
	}

	char ** temp = *p3;
	int i = 0;
	for (; i < len3; i++)	//先释放二级内存
		if (temp[i] != NULL)
		{
			free(temp[i]);
			temp[i] = NULL;
		}
	free(temp);				//再释放一级内存
	*p3 = NULL;
	printf("free done\n");
	return res;
}

int sort(char ** array1, int num1, char(*array2)[30], int num2, char *** myp3 /*out*/, int * num3)
{
	int res = 0;
	if (array1 == NULL || array2 == NULL || myp3 == NULL || num3 == NULL)
	{
		res = -1;
		fprintf(stderr, "func sort NULL pointer\n");
		return res;
	}
	
	int num = num1 + num2;
	char ** temp = (char**)calloc(num, sizeof(char*));	//分配一级数组空间
	if (temp == NULL)
	{
		res = -2;
		fprintf(stderr, "main calloc failed\n");
		return res;
	}
	
	int i = 0;
	for (i = 0; i < num1; i++)				//分配二级数组空间--1
	{
		int len = strlen(array2[i]);
		temp[i] = (char*)calloc(len, sizeof(char));
		if (temp[i] == NULL)
		{
			res = -3;
			fprintf(stderr, "deputy1 calloc failed\n");
			free_buf(&temp, i);
			return res;
		}

		strncpy(temp[i], array1[i], len);	//用了calloc，temp[i][len - 1]不用再写='\0';
		temp[i][len - 1] = '\0';			//可省略
	}

	int j = 0;
	for (j = 0; j < num2; j++)				//分配二级数组空间--1
	{
		int len = strlen(array2[j]);
		temp[i + j] = (char*)calloc(len, sizeof(char));
		if (temp[i + j] == NULL)
		{
			res = -4;
			fprintf(stderr, "deputy2 calloc failed\n");
			free_buf(&temp, i + j);
			return res;
		}
		
		strncpy(temp[i + j], array2[j], len);
		temp[i + j][len - 1] = 0;			//可省略
	}

	for (i = 0; i < num - 1; i++)			//选择排序
		for (j = i + 1; j < num; j++)
			if (strcmp(temp[i], temp[j]) > 0)
			{
				char * swap = temp[i];		//地址交换
				temp[i] = temp[j];
				temp[j] = swap;
			}

	*myp3 = temp;
	*num3 = num;
	return res;
}