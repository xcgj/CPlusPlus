#include <iostream>
using std::cout;
using std::endl;

class Concrete
{
public:
	int a;
	void func()
	{
		cout << "func of Concrete. a = " << a << endl;
	}
};

class Derive :public Concrete
{
public:
	int a;
	void func()
	{
		cout << "func of Concrete. a = " << a << endl;
	}
};

int main(void)
{
	Derive q;
	q.a = 10;	//��Ч�ڣ�	q.Derive::a = 10;
	q.func();	//Ĭ�ϵ����������ͬ�������ͺ���
	q.Concrete::a = 50;
	q.Concrete::func();	//��ʽ���û����ͬ�������ͺ���
	cout << "&q.a = " << &q.a <<
		"   &q.Concrete::a = " << &q.Concrete::a << endl;
	return 0;
}

/*
func of Concrete. a = 10
func of Concrete. a = 50
&q.a = 0135F730   &q.Concrete::a = 0135F72C

1 ͬ����Ա�洢���ڴ��еĲ�ͬλ��
2 �����Ա�� ���������쵽����������
3 ��������������λ����ͬ��
4 ͬ����Ա�����ͳ�Ա����ͨ��������ֱ�� :: ��������
*/

