/*
有个莲花池里起初有一只莲花，每过一天莲花的数量就会翻一倍。
假设莲花永远不凋谢，30天的时候莲花池全部长满了莲花, 
请问第23天的莲花占莲花池的几分之几？
*/
#include <stdio.h>
//找终止条件，那个变量（这个变量一般是函数的形参）变化到哪个值会返回哪个数（返回值）
//找变量变化关系，代入参数列表
//找返回值和函数的关系，上一次计算的结果和本次调用的函数有什么关系

unsigned int numLotus(int d)
{
	if (d == 1)
		return 1;
	return (unsigned int)(2 * numLotus(d - 1));
}

int main(void)
{
	int m = 23;
	if (m > 30 && m < 1)
		return -1;
	int n = numLotus(30) / numLotus(m);//莲花每天翻倍，后面天数的莲花数量肯定整除前面的数量
	printf("第%d天的莲花占莲花池的%d分之1\n", m, n);
	return 0;
}