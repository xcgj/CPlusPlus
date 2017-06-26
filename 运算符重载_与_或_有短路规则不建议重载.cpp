#include <iostream>
using std::cout;
using std::endl;

class A
{
private:
	int m, n;
public:
	A(int j, int k)
	{
		m = j, n = k;	//���ű��ʽ
	}

	A operator+(A &z)
	{
		cout << "+���������������" << this->m + z.m << "  " << this->n + z.n << endl;
		return A(this->m + z.m, this->n + z.n);	//����Ԫ��
	}

	bool operator&&(A &x)
	{
		cout << "&&���������������" << endl;
		return (this->m + this->n) && (x.m + x.n);
	}

	bool operator||(A &y)
	{
		cout << "||���������������" << endl;
		return (this->m + this->n) || (y.m + y.n);
	}
};

int main(void)
{
	A a(1, -1), b(2, 3);
	cout << "a && (a + b) = " << ((a + a) && (a + b)) << endl;
	//������������a+a��a+b��������
	cout << "a || (a + b) = " << ((a + a) || (a + b)) << endl;
	//������������a+a��������a+b
}
/*
��������
+���������������3  2		//a+b
+���������������2  -2	//a+a
&&���������������
a && (a + b) = 0
+���������������3  2		//a+b
+���������������2  -2	//a+a
||���������������
a || (a + b) = 1

���ϲ�δʵ�ֶ�·������˲��������� && �� ||
*/