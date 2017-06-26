#include <iostream>
using namespace std;

class Concrete
{
public:
	void func()		//函数重载
	{
		cout << "func none" << endl;
	}

	void func(int a)//函数重载
	{
		cout << "func 1" << endl;
	}

	void print()
	{
		cout << "func print" << endl;
	}
};

class Derive :public Concrete
{
public:
	void func(int a, int b)//函数重写--重定义
	{
		cout << "func 2" << endl;
	}
};

int main(void)
{
	Derive m;
	//m.func();	//错误，派生类的同名函数覆盖了基类的同名函数
	m.Concrete::func();	//域作用符显式调用父类同名函数
	m.func(1, 2);
	m.print();	//子类没有与父类同名的函数才会直接去父类找这个函数调用
	return 0;
}
//子类无法重载父类函数父类同名函数将被名称覆盖
//注意区分	这种情况是	子类定义对象调用同名函数
//			多态的情况	父类指针指向子类对象，调用同名函数