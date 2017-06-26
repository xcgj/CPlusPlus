#include "iostream"
using std::cout;
using std::endl;
//��Ҳ��һ���û��Զ�����������ͣ�C++��������֪���������
//���������ṩ��һ�ֻ��ƣ����Զ������������л��������������м���==>���������
class B
{
private:
};

class A
{
public:
	int a;
	int b;
public:
	A(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void print()
	{
		cout << a << "+" << b << "i" << endl;
	}
	A operator-(A &t)
	{
		return A(this->a - t.a, this->b - t.b);	//��Ա����ʵ�����������
	}
};

A myAdd(A &a, A &b)
{
	A c(a.a + b.a, a.b + b.b);
	return c;
}

A operator+(A &a, A &b)	//ȫ�ֺ���ʵ�����������
{
	A c(a.a + b.a, a.b + b.b);
	return c;
}

int main(void)
{
	A x(5, 6), y(7, 8);
	A z = myAdd(x, y);
	z.print();
	z = operator+(x, y);
	z.print();
	z = x + y;
	z.print();	//������ȫ�ֺ��� operator+�� +������
	z = y.operator-(x);
	z.print();
	z = y - x;	//�����˳�Ա���� operator-
	z.print();
	return 0;
}
//�ܽ᣺ ��������صı��ʣ���������