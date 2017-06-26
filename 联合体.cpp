#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union A
{
	int i;
	char s;
	char d[2];
};

int main(void)
{
	int i;
	printf("%p\n", &i);
	char *p = (char*)&i;
	p[0] = 1;

	A a;
	printf("%p\n", &a);

	A b;
	printf("%p\n", &b);
	b.s = 1;

	A c;
	printf("%p\n", &c);
	c.d[0] = 1;

	A f;
	printf("%p\n", &f);
	f.d[0] = 1;
	f.d[1] = 2;
	return 0;
}
