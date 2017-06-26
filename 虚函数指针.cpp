#include <iostream>
using namespace std;

class Concrete
{
public:
	Concrete(int a)
	{
		print();
	}

	virtual void print()
	{
		cout << "concrete" << endl;
	}
};

class Derive :public Concrete
{
public:
	Derive(int a, int b) :Concrete(a)
	{
		print();
	}

	virtual void print()
	{
		cout << "derive" << endl;
	}
};

int main(void)
{
	Derive test(1, 2);
	return 0;
}

/*
��ʼ�� Derive.vptrָ�룬�Ƿֲ����
��ִ�и���Ĺ��캯��ʱ��Derive.vptrָ��ָ������麯���б���˵����˸����print()����
������Ĺ��캯��������Ϻ�Derive.vptrָ��Ż�ָ��������麯���б�

���ۣ�
�����vptrָ��ֲ���ɣ�����Ķ�����ʱ���ڸ���Ĺ��캯�������麯�����������˶�̬
*/