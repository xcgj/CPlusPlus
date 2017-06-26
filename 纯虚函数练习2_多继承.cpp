#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Concrete1
{
public:
	virtual void add(int a, int b) = 0;
	virtual void print() = 0;
};

class Concrete2
{
public:
	virtual void add(int a, int b) = 0;
	virtual void print() = 0;
};

class Derive : public Concrete1, public Concrete2
{
public:
	virtual void add(int a, int b)
	{
		sum = a + b;
	}
	virtual void print()
	{
		cout << "sum = " << sum << endl;
	}
private:
	int sum;

};

int main(void)
{
	Concrete1 *m;
	Concrete2 *n;
	Derive x;
	m = &x;
	n = &x;


	m->add(2, 3);	//父类1操作子类赋值
	n->print();		//父类2操作子类输出

	cout << "Compelete" << endl;;
	return 0;
}