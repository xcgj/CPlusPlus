/*
已知 char **p = NULL; int lines 编写读文件函数，从文件中读取内容，为每一行内容按大小分配空间。
void readFile(char ***p,int *line);

文件内容参考《demo.txt》

提示：
首先扫描文件行数，根据行数给指针p分配指针数组空间。
再根据每行内容，动态分配空间，存放每行内容。
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funFree(char ***p, int line)
{
	int res = 0;
	if (p == NULL || *p == NULL)
	{
		res = -1;
		printf("func funFree NULL pointer\n");
		return;
	}

	char **temp = *p;
	for (int i = 0; i < line; i++)
	{
		if (temp[i] != NULL)
		{
			free(temp[i]);
			temp[i] = NULL;
		}
	}
	
	printf("memory freed\n");
	free(temp);
	*p = NULL;
}

int print(char **p, int line)
{
	int res = 0;
	if (p == NULL)
	{
		res = -1;
		printf("func print NULL pointer\n");
		return res;
	}

	for (int i = 0; i < line; i++)
	{
		printf("%s", p[i]);
	}

	return res;
}

int readFile(char ***p, int *line)
{
	int res = 0;
	if (p == NULL || line == NULL)
	{
		res = -1;
		printf("func readFile NULL pointer\n");
		return res;
	}

	FILE *pf = fopen("demo.txt", "r");
	if (pf == NULL)
	{
		res = -2;
		printf("no file\n");
		return res;
	}

	char buf[4096] = { 0 };
	int count = 0;
	while (fgets(buf, sizeof(buf), pf))
		count++;	//行数

	char ** temp = (char **)calloc(count, sizeof(char*));
	if (temp == NULL)
	{
		res = -3;
		printf("allocate1 failed\n");
		return res;
	}

	fseek(pf, 0, SEEK_SET);
	memset(buf, 0, sizeof(buf));
	for (int i = 0; fgets(buf, sizeof(buf), pf); i++)
	{
		int length = strlen(buf);	//每行字符串长度
		temp[i] = (char*)calloc(length + 1, sizeof(char));
		if (temp == NULL)
		{
			res = -4;
			printf("allocate2 failed\n");
			funFree(&temp, count);
			return res;
		}
		strcpy(temp[i], buf);
		//temp[i][length] = '\0';	//可不写，有calloc
		memset(buf, 0, sizeof(buf));
	}

	fclose(pf);
	*p = temp;
	*line = count;
	return res;
}

int main(void)
{
	char **p = NULL; 
	int lines;
	int res = readFile(&p, &lines);
	//printf("%d\n", lines);

	res = print(p, lines);
	//printf("%d\n", res);
	
	funFree(&p, lines);
	printf("Compelete\n");
	return 0;
}
