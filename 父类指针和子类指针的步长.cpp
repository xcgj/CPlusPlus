#include <iostream>
using namespace std;

class Concrete
{
public:
	int a;
	Concrete(int a)
	{
	}

	virtual void print()
	{
		cout << "concrete" << endl;
	}
};

class Derive :public Concrete
{
public:
	int b;	//�������ӵĳ�Ա�˱��������¸��������Ĵ�С��һ����
	Derive(int a) :Concrete(a)
	{
	}

	virtual void print()
	{
		cout << "derive" << endl;
	}
};

int main(void)
{
	Derive test[] = { (1), (2), (3) };
	Concrete *pC = test;	//���常��ָ��ָ���������������׵�ַ
	Derive *pD = test;		//��������ָ��ָ���������������׵�ַ
	//��һ�ε��ú���
	pC->print();
	pD->print();
	//�ڶ��ε��ú���
	pC++;	//ָ����һ�������������ʹ�С
	pD++;	//ָ����һ�������������ʹ�С
	pC->print();
	pD->print();
	//�����ε��ú���
	pC++;
	pD++;
	pC->print();
	pD->print();
	return 0;
}

/*
���ۣ�
����ָ�벻����++�ķ�ʽ��������������飬����������ʹ�С��һ�����������
*/