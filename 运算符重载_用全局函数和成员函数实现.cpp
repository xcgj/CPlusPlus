#include "iostream"
using std::cout;
using std::endl;
//类也是一种用户自定义的数据类型，C++编译器不知道如何运算
//编译器便提供了一种机制，让自定义数据类型有机会操作运算符进行计算==>运算符重载
class B
{
private:
};

class A
{
public:
	int a;
	int b;
public:
	A(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void print()
	{
		cout << a << "+" << b << "i" << endl;
	}
	A operator-(A &t)
	{
		return A(this->a - t.a, this->b - t.b);	//成员函数实现运算符重载
	}
};

A myAdd(A &a, A &b)
{
	A c(a.a + b.a, a.b + b.b);
	return c;
}

A operator+(A &a, A &b)	//全局函数实现运算符重载
{
	A c(a.a + b.a, a.b + b.b);
	return c;
}

int main(void)
{
	A x(5, 6), y(7, 8);
	A z = myAdd(x, y);
	z.print();
	z = operator+(x, y);
	z.print();
	z = x + y;
	z.print();	//调用了全局函数 operator+， +号重载
	z = y.operator-(x);
	z.print();
	z = y - x;	//调用了成员函数 operator-
	z.print();
	return 0;
}
//总结： 运算符重载的本质：函数调用