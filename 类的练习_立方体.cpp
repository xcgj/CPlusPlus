#include "iostream"
using namespace std;
#include "cube.h"

int main(void)
{
	int arris = 0;
	cube x;
	cout << "棱长";
	cin >> arris;
	x.GetRidge(arris);
	cout << "面积" << x.Proportion() << endl;
	cout << "体积" << x.Cubature() << endl;
	return 0;
}
//题解
//定义立方体的类
//类里面有接收立方体棱长的函数
//在类里面 声明 并 实现 面积 和 体积 的函数