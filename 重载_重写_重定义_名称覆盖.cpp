#include <iostream>
using namespace std;

class Concrete
{
public:
	void func()		//��������
	{
		cout << "func none" << endl;
	}

	void func(int a)//��������
	{
		cout << "func 1" << endl;
	}

	void print()
	{
		cout << "func print" << endl;
	}
};

class Derive :public Concrete
{
public:
	void func(int a, int b)//������д--�ض���
	{
		cout << "func 2" << endl;
	}
};

int main(void)
{
	Derive m;
	//m.func();	//�����������ͬ�����������˻����ͬ������
	m.Concrete::func();	//�����÷���ʽ���ø���ͬ������
	m.func(1, 2);
	m.print();	//����û���븸��ͬ���ĺ����Ż�ֱ��ȥ�����������������
	return 0;
}
//�����޷����ظ��ຯ������ͬ�������������Ƹ���
//ע������	���������	���ඨ��������ͬ������
//			��̬�����	����ָ��ָ��������󣬵���ͬ������