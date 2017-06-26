#include <iostream>
using namespace std;

class Concrete
{
public:
	virtual void print()	//父类函数加 virtual 关键字表示这个函数是多态，如果父类不加，子类加了也无效
	{
		cout << "Concrete print" << endl;
	}
};

class Derive:public Concrete
{
public:
	virtual void print()	//子类可以不用加，一般加上便于区分
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