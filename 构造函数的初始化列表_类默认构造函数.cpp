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
		cout << "����a" << a << endl;
	}

private:
	int a;
};

class H
{
public:
	H(int x, int y, int m, int n)//���캯������2
	{
		i = x;
		j = y;
		cout << "����h" << i << endl;
	}

	~H()
	{
		cout << "����h" << i << endl;
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
��A��Ĭ�Ϲ��캯�����ᱨ��
*/