#include <iostream>
using namespace std;
//	=	�Ų����������ڶ�������ݸ���
// ֻ�����ڳ�Ա����
// C++�������ṩ�� �ȺŲ��� Ҳ�� ǳ����
class A
{
	int a;
public:
	A(int b = 0)
	{
		this->a = b;
		cout << "constructor a = " << a << endl;
	}

	A& operator=(A &b)
	{
		cout << "before copy, this->a = " << a << endl;
		this->a = b.a;
		cout << "after copy, this->a = " << a << endl;
		return *this;	//��������������ʽ��̣��ظ���ֵ��
	}

	void print()
	{
		cout << "a = " << a << endl;
	}
	
};

int main(void)
{
	A m(4), n, w(100);
	n = m = w;	//m������a���Ƹ�n������a
	n.print();
	m.print();
	w.print();
	return 0;
}
/*
��Ļ�������=���Ǵ����������㣩
constructor a = 4
constructor a = 0
constructor a = 100
before copy, this->a = 4	//w.a���Ƹ�m.a
after copy, this->a = 100
before copy, this->a = 0	//m.a���Ƹ�n.a
after copy, this->a = 100
a = 100						//��֤3�������a����100
a = 100
a = 100
*/