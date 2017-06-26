#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int doub(int x)
{
	if (x == 1)
		return 1;//终止条件
	return x * doub(x - 1);
}
//变量变化关系是x-1
int main(void)
{
	int a = 5;
	int b = doub(a);
	printf("%d\n", b);
	return 0;
}
//递归结论
//找终止条件，那个变量（这个变量一般是函数的形参）变化到哪个值会返回哪个数（返回值）
//找变量变化关系，代入参数列表
//找返回值和函数的关系，上一次计算的结果和本次调用的函数有什么关系