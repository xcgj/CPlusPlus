/*
有一个字符串符合以下特征 "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
a) 以逗号, 隔开字串，字串数量不会超过10个，每个字串长度不会超过30
b) 以逗号分隔字符串，并把结果传出
c)参考库函数：strchr(), strncpy(), strcpy(), strlen()
不能使用strtok()

功能：把 "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"，以","分隔出字符串，分配放在二维数组buf中
参数：
str：	原字符串，"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
c：	 	分隔标志：','
buf: 	指针数组首元素地址，其空间在主调函数分配
count：保存buf字符串的个数
返回值：
成功：0
失败：非0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMemFree(char *** buf, int n)
{
	int res = 0;
	if (buf == NULL || *buf == NULL)
	{
		res = -1;
		fprintf(stderr, "func getMemFree NULL pointer\n");
		return res;
	}

	char ** temp = *buf;
	for (int i = 0; i < n; i++)
		if (temp[i] != NULL)
		{
			free(temp[i]);
			temp[i] = NULL;
		}
	free(temp);
	*buf = NULL;

	printf("Note: memory freed\n");
	return res;
}

char ** getMem(int n)
{
	char ** temp = (char**)calloc(n, sizeof(char*));		//分配一维数组	
	if (temp == NULL)
	{
		fprintf(stderr, "One-dimension Space allocate failed\n");
		return NULL;
	}

	/*
	for (int i = 0; i < n; i++)
	{
		temp[i] = (char*)calloc(30, sizeof(char));			//分配二维数组
		if (temp == NULL)
		{
			fprintf(stderr, "Two-dimension Space allocate failed\n");
			getMemFree(&temp, i);
			return NULL;
		}
	}
	*/
	return temp;
}

int spitString(const char *str, char c, char **buf, int *count)
{
	int res = 0;
	if (str == NULL || buf == NULL || count == NULL)
	{
		res = -1;
		fprintf(stderr, "func spitString NULL pointer\n");
		return res;
	}

	const char * t_str = str;	//辅助指针
	int n = 1;					//str非空，肯定有一个子串
	while (t_str = strchr(t_str, c))
	{
		t_str++;				//掠过指定字符
		n++;					//计算子串的数量
	}

	t_str = str;				//恢复辅助指针指向
	const char * start = t_str;	//用来计算长度的指针
	for (int i = 0; i < n; i++)	//二维数组分配空间，拷贝内容
	{
		int len = 0;
		t_str = strchr(t_str, c);

		if (t_str == NULL)
			len = strlen(start);
		else
			len = t_str - start;

		buf[i] = (char*)calloc(len + 1, sizeof(char));//C风格字符串
		if (buf[i] == NULL)
		{
			res = -1;
			fprintf(stderr, "Two-dimension Space allocate failed\n");
			getMemFree(&buf, i);
			return res;
		}

		strncpy(buf[i], start, len);
		buf[i][len] = '\0';		//C风格字符串

		if (t_str == NULL)
			break;
		t_str++;				//掠过指定字符
		start = t_str;
	}

	*count = n;
	return res;
}

int main()
{
	char *p = ",abcdef,acccd,eeee,  ,aaaa,e3eeee,ssss,";
	char **buf = getMem(10); //动态打造指针数组
	if (buf == NULL)
	{
		printf("func getMem failed\n");
		return -1;
	}

	int n = 0;
	int ret = 0;

	ret = spitString(p, ',', buf, &n);
	if (ret != 0)
		return ret;

	int i = 0;
	for (i = 0; i < n; i++)
		printf("%s\n", buf[i]); //打印分隔后的字符串

	getMemFree(&buf, n); //释放空间

	return 0;
}
