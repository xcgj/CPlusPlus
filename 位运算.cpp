/*
����һ���޷��ŵ����У�������λ��ֵΪ 1 �ĸ���
��ʾ��>>

int count_one_bits(unsigned int tmp)
{

}
*/
#include <stdio.h>

int count_one_bits(unsigned int tmp)
{
	int count = 0;
	while (tmp)
	{
		if (tmp % 2)
			count++;
		tmp >>= 1;
	}
	return count;
}

int main(void)
{
	unsigned int a = 3;
	int res = count_one_bits(a);
	printf("res = %d\n", res);
	return 0;
}
