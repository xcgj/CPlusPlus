#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void defau(int x = 5)
{
	printf("%d\n", x);
}

int main(void) 
{
	defau(3);
	defau();
	printf("\n");
	return 0;
}