//当时的情况是这样的：
// 第一天悟空吃掉桃子总数一半多一个，第二天又将剩下的桃子吃掉一半多一个，以后每天吃掉前一天剩下的一半多一个，
//到第n天准备吃的时候只剩下一个桃子。
//聪明的你，请帮悟空算一下，他第一天开始吃的时候桃子一共有多少个呢？
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//终止条件：第n天返回1
int peach(int n)
{
	if (n == 1)
		return 1;
	return (1 + peach(n - 1)) * 2;
}

int main01(void)
{
	int x = 10;
	int y = peach(x); //天数
	printf("%d\n", y);
	return 0;
}
//1			x
//2			x/2-1
//3			()/2-1

//n-1		(1+1)*2
//n			1

//递归结论
//找终止条件，那个变量（这个变量一般是函数的形参）变化到哪个值会返回哪个数（返回值）
//找变量变化关系，代入参数列表
//找返回值和函数的关系，上一次计算的结果和本次调用的函数有什么关系