#include <iostream>
using std::cout;
using std::endl;

class Concrete1
{
public:
	int a;
	void func()
	{
		cout << "func of Concrete1. a = " << a << endl;
	}
	Concrete1(int a)
	{
		this->a = a;
		cout << "constructor of Concrete1" << endl;
	}
};

class Concrete2
{
public:
	int a;
	void func()
	{
		cout << "func of Concrete2. a = " << a << endl;
	}
	Concrete2(int a)
	{
		this->a = a;
		cout << "constructor of Concrete2" << endl;
	}
};

class Derive :public Concrete1, public Concrete2
{
public:
	int a;
	void func()
	{
		cout << "func of Concrete. a = " << a << endl;
	}

	Derive(int a, int b, int c):Concrete2(a), Concrete1(b)
	{
		this->a = c;
		cout << "constructor of Derive" << endl;
	}
};

int main(void)
{
	Derive q(9, 8, 7);
	q.func();	//默认调用派生类的同名变量和函数
	q.Concrete1::func();
	q.Concrete2::func();	//显式调用基类的同名变量和函数
	return 0;
}

/*
constructor of Concrete1
constructor of Concrete2
constructor of Derive
func of Concrete. a = 7
func of Concrete1. a = 8
func of Concrete2. a = 9

构造函数调用按照基类继承的顺序来
*/

