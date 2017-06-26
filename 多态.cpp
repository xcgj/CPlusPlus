#include <iostream>
using namespace std;

class Concrete
{
public:
	virtual void print()	//���ຯ���� virtual �ؼ��ֱ�ʾ��������Ƕ�̬��������಻�ӣ��������Ҳ��Ч
	{
		cout << "Concrete print" << endl;
	}
};

class Derive:public Concrete
{
public:
	virtual void print()	//������Բ��üӣ�һ����ϱ�������
	{
		cout << "Derive print" << endl;
	}
};

int main(void)
{
	Concrete a, *p = NULL;
	Derive b;
	p = &a;
	p->print();

	p = &b;
	p->print();
	return 0;
}