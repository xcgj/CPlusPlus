/*
��д�����ļ�д����
a) �����ϵ����ӣ���ʱ�����Ƿ���ջ�����飬Ȼ��ر��ļ����ٰ���ʱ��������д���ļ�
b) ����ʱ������ڶ�����������С����һ���Ծͷ���ã�����ͨ��realloc���䣬��������

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*
	int len = strlen(buf);	ÿ��ȡһ�ε��ַ�������
	size += len;	����Ҫ������ܴ�С
	char * temp = (char *)realloc(size + len + 1, sizeof(char));
	if(temp == NULL){...}
	strcat(temp, p);
	strcat(temp, buf);
	temp[size + len] = '\0';	c����ַ���
	p = temp;
	*/
	printf("Compelete\n");
	return 0;
}
