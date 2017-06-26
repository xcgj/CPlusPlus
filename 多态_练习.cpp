#include <iostream>
using namespace std;

class Concrete
{
public:
	virtual int score()	//����
	{
		return 0;
	}
};

class GET1 :public Concrete	//����
{
public:
	virtual int score()
	{
		return 80;
	}
};

class GET2 :public Concrete	//����
{
public:
	virtual int score()
	{
		return 100;
	}
};

class Cartest	//�ݿ���
{
public:
	int passline()
	{
		return 90;
	}
};

void exam(Concrete &stu, Cartest &sys)
{
	int a = stu.score();	//�������ຯ��
	int b = sys.passline();
	if (a >= b)
		cout << "pass" << endl;
	else
		cout << "deny" << endl;
}

int main(void)
{
	GET1 m;
	GET2 n;
	Cartest b;

	exam(m, b);	//�����������
	exam(n, b);

	return 0;
}