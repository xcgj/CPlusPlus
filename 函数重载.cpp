#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void(*pfunc)(int a, int b);

void overload(int n, char m) //char类型和 函数指针 /定义/ 参数2的int类型 不匹配，不会调用这个函数
{
	printf("func 1 \n");
}

void overload(int x, int y)
{
	printf("func 2 \n");
}

void overload(int x, int d, int c = 0)//默认参数
{
	printf("func 2 \n");
}

int main(void) 
{
	int a = 0;
	char b = 1;
	pfunc p;
	p = overload;
	p(a, b);	//输出 func 2
	printf("\n");
	return 0;
}