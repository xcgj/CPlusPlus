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
	int b;	//额外增加的成员了变量，导致父类和子类的大小不一样了
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
	Concrete *pC = test;	//定义父类指针指向子类对象数组的首地址
	Derive *pD = test;		//定义子类指针指向子类对象数组的首地址
	//第一次调用函数
	pC->print();
	pD->print();
	//第二次调用函数
	pC++;	//指针走一个父类数据类型大小
	pD++;	//指针走一个子类数据类型大小
	pC->print();
	pD->print();
	//第三次调用函数
	pC++;
	pD++;
	pC->print();
	pD->print();
	return 0;
}

/*
结论：
父类指针不能用++的方式操作子类对象数组，如果数据类型大小不一样，程序崩溃
*/