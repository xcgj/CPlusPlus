#include <stdio.h>

int main()
{
	char a[4] = { 1, 2, 3, 4 };
	char *p = a;
	printf("%d, %d, %d, %d\n", *p, *(p + 1), *(p + 2), *(p + 3));

	int *p1 = (int *)a;//��a�ĵ�ַǿתΪint *����
	printf("%d\n", *p1);	
	printf("%x\n", *p1);	

	return 0;
}
