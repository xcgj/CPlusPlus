/*
ʵ��my_strstr()���������ܺ�strstr()����һ����
a. �����в�ʹ���κβ����ַ����ĺ���(�磺strcpy��strcmp��)
b. �����е��κεط���ʹ���±ꡣ

���ܣ����ַ���haystack�в����ַ���needle���ֵ�λ��
������
haystack��Դ�ַ����׵�ַ
needle��ƥ���ַ����׵�ַ
����ֵ��
�ɹ������ص�һ�γ��ֵ�needle��ַ
ʧ�ܣ�NULL

char *my_strstr(const char *haystack, const char *needle);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *my_strstr(const char *haystack, const char *needle)
{
	const char *temp = haystack;		//����ָ��

	int h_len = 0;						//ԭʼ�ַ�������
	for (; *(temp + h_len); h_len++);	//len����ֵ��\0���ڵ��±�λ�ã����ַ�������
	int n_len = 0;						//ƥ���ַ�������
	for (; *(needle + n_len); n_len++);	//len����ֵ��\0���ڵ��±�λ�ã����ַ�������

	int i = 0;
	for (; i < h_len; i++)
		if (*(temp + i) == *(needle))	//ƥ�䵽��һ���ַ�
		{
			int j = 0;
			int flag = 1;				//��Ƿ�
			const char *ttemp = temp + i;	//����ָ��
			for (; j < n_len; j++)		//��֤�����ַ���ƥ��
			{
				if (*(ttemp + j) != *(needle + j))//ƥ��ʧ������ѭ��
				{
					flag = 0;
					break;
				}
			}
			if (flag)					//ƥ��ɹ�������ѭ��
				return (char*)ttemp;
		}
	return NULL;
}

int main(void)
{
	const char *a = "abcdefghijklmn";
	const char *b = "ghia";
	char *p = my_strstr(a, b);
	printf("%p\n", p);
	return 0;
}