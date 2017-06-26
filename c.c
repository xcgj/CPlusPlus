#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *s = "asdfjk\0hjkahsdflhsdak";
	int len = 12;
	printf("%s %d\n", s, len);
	return 0;
}
