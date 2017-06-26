/*
��һ���ַ��������������� "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
a) �Զ���, �����ִ����ִ��������ᳬ��10����ÿ���ִ����Ȳ��ᳬ��30
b) �Զ��ŷָ��ַ��������ѽ������
c)�ο��⺯����strchr(), strncpy(), strcpy(), strlen()
����ʹ��strtok()

���ܣ��� "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"����","�ָ����ַ�����������ڶ�ά����buf��
������
str��	ԭ�ַ�����"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
c��	 	�ָ���־��','
buf: 	ָ��������Ԫ�ص�ַ����ռ���������������
count������buf�ַ����ĸ���
����ֵ��
�ɹ���0
ʧ�ܣ���0
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
	char ** temp = (char**)calloc(n, sizeof(char*));		//����һά����	
	if (temp == NULL)
	{
		fprintf(stderr, "One-dimension Space allocate failed\n");
		return NULL;
	}

	/*
	for (int i = 0; i < n; i++)
	{
		temp[i] = (char*)calloc(30, sizeof(char));			//�����ά����
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

	const char * t_str = str;	//����ָ��
	int n = 1;					//str�ǿգ��϶���һ���Ӵ�
	while (t_str = strchr(t_str, c))
	{
		t_str++;				//�ӹ�ָ���ַ�
		n++;					//�����Ӵ�������
	}

	t_str = str;				//�ָ�����ָ��ָ��
	const char * start = t_str;	//�������㳤�ȵ�ָ��
	for (int i = 0; i < n; i++)	//��ά�������ռ䣬��������
	{
		int len = 0;
		t_str = strchr(t_str, c);

		if (t_str == NULL)
			len = strlen(start);
		else
			len = t_str - start;

		buf[i] = (char*)calloc(len + 1, sizeof(char));//C����ַ���
		if (buf[i] == NULL)
		{
			res = -1;
			fprintf(stderr, "Two-dimension Space allocate failed\n");
			getMemFree(&buf, i);
			return res;
		}

		strncpy(buf[i], start, len);
		buf[i][len] = '\0';		//C����ַ���

		if (t_str == NULL)
			break;
		t_str++;				//�ӹ�ָ���ַ�
		start = t_str;
	}

	*count = n;
	return res;
}

int main()
{
	char *p = ",abcdef,acccd,eeee,  ,aaaa,e3eeee,ssss,";
	char **buf = getMem(10); //��̬����ָ������
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
		printf("%s\n", buf[i]); //��ӡ�ָ�����ַ���

	getMemFree(&buf, n); //�ͷſռ�

	return 0;
}
