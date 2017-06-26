#include <iostream>
using std::cout;
using std::endl;

class Concrete
{
public:
	int a;
	void func()
	{
		cout << "func of Concrete. a = " << a << endl;
	}
};

class Derive :public Concrete
{
public:
	int a;
	void func()
	{
		cout << "func of Concrete. a = " << a << endl;
	}
};

int main(void)
{
	Derive q;
	q.a = 10;	//等效于：	q.Derive::a = 10;
	q.func();	//默认调用派生类的同名变量和函数
	q.Concrete::a = 50;
	q.Concrete::func();	//显式调用基类的同名变量和函数
	cout << "&q.a = " << &q.a <<
		"   &q.Concrete::a = " << &q.Concrete::a << endl;
	return 0;
}

/*
func of Concrete. a = 10
func of Concrete. a = 50
&q.a = 0135F730   &q.Concrete::a = 0135F72C

1 同名成员存储在内存中的不同位置
2 基类成员的 作用域延伸到所有派生类
3 派生类的重名屏蔽基类的同名
4 同名成员变量和成员函数通过作用域分辨符 :: 进行区分
*/

