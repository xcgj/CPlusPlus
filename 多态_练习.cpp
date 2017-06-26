#include <iostream>
using namespace std;

class Concrete
{
public:
	virtual int score()	//父类
	{
		return 0;
	}
};

class GET1 :public Concrete	//子类
{
public:
	virtual int score()
	{
		return 80;
	}
};

class GET2 :public Concrete	//子类
{
public:
	virtual int score()
	{
		return 100;
	}
};

class Cartest	//驾考类
{
public:
	int passline()
	{
		return 90;
	}
};

void exam(Concrete &stu, Cartest &sys)
{
	int a = stu.score();	//调用子类函数
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

	exam(m, b);	//引用子类对象
	exam(n, b);

	return 0;
}