/*
* 实现一个十进制转二进制的函数，传入一个十进制数，以二进制形式输出
* void dec2bin(int n);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main04();

extern const int a = 100;

int main(void)
{
	main04();
	unsigned int a = 173;
	char s[1024] = { 0 };
	while (a)
	{
		if (a % 2)
			strncat(s, "1", 1);
		else
			strncat(s, "0", 1);
		a >>= 1;
	}

	int min = 0;
	int len = strlen(s) - 1;
	while (min < len)
	{
		s[min] = s[min] ^ s[len];
		s[len] = s[min] ^ s[len];
		s[min] = s[min] ^ s[len];
		min++, len--;
	}

	printf("%s\n", s);
	return 0;
}
