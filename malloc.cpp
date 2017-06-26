#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* func(int size)
{
	int *temp = (int *)calloc(size , sizeof(int));
	return temp;
}

int main(void)
{
	int *p = func(100);
	printf("Compelete\n");
	free(p);
	return 0;
}
