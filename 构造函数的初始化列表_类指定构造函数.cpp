#include "iostream"
using namespace std;

class A
{
public:
	A(int x)
	{
		a = x;
		cout << "����a" << a << endl;
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
	H(int x, int y) :a1(10), a2(20)	//���캯������1
	{
		i = x;
		j = y;
		cout << "����h" << i << endl;
	}

	H(int x, int y, int m, int n) :a2(m), a1(n)	//���캯������2
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
/* ��B�Ĺ��캯�������������ĵ���˳��
�����϶��󰴶���˳����ù��캯���������ǰ���ʼ���б�˳�����
��������˳��͹��캯���෴
����a4
����a3
����h1
����h1
����a3
����a4
 */