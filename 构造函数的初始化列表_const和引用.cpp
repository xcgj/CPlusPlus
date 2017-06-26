#include "iostream"
using namespace std;

class H
{
public:
	H(int x, int y, int m, int n) : a(m), b(n), c(n)//const和引用初始化
	{
		i = x;
		j = y;
		cout << "构造h" << i << endl;
	}

	H(int x, int y) : a(1), b(y), c(8)//const和引用初始化
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
	const int a;
	int &b;
	const int &c;
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