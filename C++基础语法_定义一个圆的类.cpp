#include "iostream"	//包含c++的头文件
using namespace std;	//使用std标准的命名空间，（在这个命名空间中定义了很多标准定义）

class Circle
//定义了一个类，是个数据类型，固定内存大小的别名，在内存中没有分配空间，
//只有用类定义了对象，才有内存空间
{
public:
	double a;//半径，属性，成员变量
	double b;//周长，属性，成员变量
	double c;//面积，属性，成员变量
	double getR(double r)//从对象获得参数，成员函数
	{
		return a = r;
	}
	double getGirth()//成员函数
	{
		return b = 3.14 * 2 * a;
	}
	double getArea()//成员函数
	{
		return c = 3.14 * a * a;
	}
};

void main1()
{
	Circle a1, a2;//定义了类的两个对象（变量）
	cout << "类 Circle 的大小：" << sizeof(a1) << endl;
	//endl  换行，并刷新缓冲区
	cout << "sizeof(double)：" << sizeof(double) << endl;
	double i = 0;
	cout << "请输入半径：";
	cin >> i;
	cout << "圆的半径是" << a1.getR(i) << endl;
	cout << "圆的周长是" << a1.getGirth() << endl;
	cout << "圆的面积是" << a1.getArea() << endl << endl << endl;;

	cout << "请输入半径：";
	cin >> i;
	a2.getR(i);//给类的属性赋值
	cout << "圆的周长是" << a2.getGirth() << endl;
	cout << "圆的面积是" << a2.getArea() << endl;
}