#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int doub(int x)
{
	if (x == 1)
		return 1;//��ֹ����
	return x * doub(x - 1);
}
//�����仯��ϵ��x-1
int main(void)
{
	int a = 5;
	int b = doub(a);
	printf("%d\n", b);
	return 0;
}
//�ݹ����
//����ֹ�������Ǹ��������������һ���Ǻ������βΣ��仯���ĸ�ֵ�᷵���ĸ���������ֵ��
//�ұ����仯��ϵ����������б�
//�ҷ���ֵ�ͺ����Ĺ�ϵ����һ�μ���Ľ���ͱ��ε��õĺ�����ʲô��ϵ