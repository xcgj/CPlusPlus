#include "iostream"
using namespace std;

class A
{
public:
	A(int x)
	{
		a = x;
		cout << "构造a" << a << endl;
	}

	~A()
	{
		cout << "析构a" << a << endl;
	}

private:
	int a;
};

class H
{
public:
	H(int x, int y) :a1(10), a2(20)	//构造函数重载1
	{
		i = x;
		j = y;
		cout << "构造h" << i << endl;
	}

	H(int x, int y, int m, int n) :a2(m), a1(n)	//构造函数重载2
	{
		i = x;
		j = y;
		cout << "构造h" << i << endl;
	}

	~H()
	{
		cout << "析构h" << i << endl;
	}

private:
	int i;
	int j;
	A a1;
	A a2;
};

void test()
{
	H a(1, 2, 3, 4);
}

int main(void)
{
	test();
	return 0;
}
/* 类B的构造函数和析构函数的调用顺序：
多个组合对象按定义顺序调用构造函数，而不是按初始化列表顺序调用
析构函数顺序和构造函数相反
构造a4
构造a3
构造h1
析构h1
析构a3
析构a4
 */