#include <iostream>
using namespace std;

class A
{
public:
	virtual int func()
	{

	}
	int func(int a)
	{

	}
	int func(int a, int b)
	{

	}
	//以上三个是func函数的重载
};

class B :public A
{
	virtual int func()	//这个func()函数是对类A的func()函数的重写（多态）
	{

	}

	int func(int a)		//这个func(int a)函数是对类A的func(int a)函数的的重写（重定义）
	{

	}
};

int main(void)
{

}

/*
结论：
重载：必须在同一个类里面定义了同名函数
重写：发生在两个类之间
	虚（virtual）函数的重写就是多态
	不是虚函数的重写就是重定义
*/