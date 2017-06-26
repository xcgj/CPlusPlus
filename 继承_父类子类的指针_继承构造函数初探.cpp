#include <iostream>
using namespace::std;

class Senior
{
public:
	void print1()
	{
		cout << "class senior" << endl;
	}

	Senior()
	{
		cout << "senior constructor func" << endl;
	}

	Senior(const Senior &a)
	{
		cout << "senior copy constructor func" << endl;
	}
};

class Young :public Senior
{
public:
	void print2()
	{
		cout << "class young" << endl;
	}

	Young()
	{
		cout << "Young constructor func" << endl;
	}

	Young(const Young &a)
	{
		cout << "Young copy constructor func" << endl;
	}
};

void func(Senior &d)
{
	cout << "func" << endl;
}

int main(void)
{

	Young a;
	a.print2();
	a.print1();		//子类对象可以当作父类对象使用

	Senior b;
	cout << "pause" << endl;
	b = a;			//子类对象可以直接赋值给父类对象

	Senior c = a;	//子类对象可以直接初始化父类对象

	Senior *p = NULL;
	p = &a;			//父类指针可以直接指向子类对象
	p->print1();

	//p->print2();	//错误，p指向的类型是父类，print2()是子类的拓展函数，不是父类的函数	//多态
	func(a);		//父类引用可以直接引用子类对象

	return 0;
}

/*
输出结果分析：
senior constructor func
Young constructor func		//说明在定义子类对象a时,先调用父类构造函数,再调用子类构造函数
class young
class senior
senior constructor func		//定义对象b时调用
senior copy constructor func//初始化对象对象c = a，赋值构造函数
class senior
func
*/