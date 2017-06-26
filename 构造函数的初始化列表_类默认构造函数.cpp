#include "iostream"
using namespace std;

class A
{
public:
	A()
	{
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
	H(int x, int y, int m, int n)//构造函数重载2
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
/* 
类A是默认构造函数不会报错
*/