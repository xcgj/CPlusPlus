#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int a = 10;
	int b = 30;
	/*a = a ^ a ^ b;//�в�ͨ��10��ֵ��ʧ
	b = b ^ b ^ a;*/

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	return 0;
}
