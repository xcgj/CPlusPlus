#include <iostream>
using namespace std;

class Concrete
{
public:
	int a;
};

class C1 :virtual public Concrete	//��̳м� virtual�����ڸ�����游��֮��
{
public:
	int b;
};

class C2 :virtual public Concrete	//��̳м� virtual�����ڸ�����游��֮��
{
public:
	int c;
};

class C3 : public Concrete	//��̳м� virtual�����ڸ�����游��֮��
{
public:
	int c;
};

class A :public C1, public C2	//������ʽ�̳�
{
public:
	int d;
};

int main(void)
{
	A test;
	//test.a = 100;	//���ɷ��ʼ��������ࡰConcrete��
	test.b = 100;
	test.c = 200;
	test.d = 300;

	cout << "sizeof C2 =" << sizeof(C2) << endl;	//12	//����virtual�ؼ��ֻ��������ʽ��������
	cout << "sizeof C3 =" << sizeof(C3) << endl;	//8
	
	return 0;
}