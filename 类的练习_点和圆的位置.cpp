#include "iostream"
using namespace std;
#include "cir_and_point.h"
int main(void)
{
	cir o;
	point d;
	
	cout << "点的 x, y 坐标" << endl;
	cin >> d.point_x;
	cin >> d.point_y;

	double m, n, h;
	cout << "圆心 x, y 坐标和半径" << endl;
	cin >> m;
	cin >> n;
	cin >> h;
	o.GetPXYR(m, n, h);

	double ret = o.C_P_comp(d);
	if (ret == 0)
		cout << "在圆上" << endl;
	else if (ret > 0)
		cout << "在圆内" << endl;
	else
		cout << "在圆外" << endl;

	return 0;
}
//题解
//定义圆的类，圆心坐标 半径
//定义点 坐标
//点的坐标减去圆心坐标 求半径
//在圆或者点的类中实现 判断函数