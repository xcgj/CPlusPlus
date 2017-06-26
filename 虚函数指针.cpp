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
初始化 Derive.vptr指针，是分步骤的
在执行父类的构造函数时，Derive.vptr指针指向父类的虚函数列表，因此调用了父类的print()函数
当父类的构造函数运行完毕后，Derive.vptr指针才会指向子类的虚函数列表

结论：
子类的vptr指针分步完成，子类的对象构造时，在父类的构造函数调用虚函数，产生不了多态
*/