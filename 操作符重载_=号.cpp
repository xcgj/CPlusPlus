#include <iostream>
using namespace std;
//	=	号操作符常用于对象的数据复制
// 只能用于成员函数
// C++编译器提供的 等号操作 也属 浅拷贝
class A
{
	int a;
public:
	A(int b = 0)
	{
		this->a = b;
		cout << "constructor a = " << a << endl;
	}

	A& operator=(A &b)
	{
		cout << "before copy, this->a = " << a << endl;
		this->a = b.a;
		cout << "after copy, this->a = " << a << endl;
		return *this;	//返回自身，方便链式编程（重复赋值）
	}

	void print()
	{
		cout << "a = " << a << endl;
	}
	
};

int main(void)
{
	A m(4), n, w(100);
	n = m = w;	//m的属性a复制给n的属性a
	n.print();
	m.print();
	w.print();
	return 0;
}
/*
屏幕输出：（=号是从右往左运算）
constructor a = 4
constructor a = 0
constructor a = 100
before copy, this->a = 4	//w.a复制给m.a
after copy, this->a = 100
before copy, this->a = 0	//m.a复制给n.a
after copy, this->a = 100
a = 100						//验证3个对象的a都是100
a = 100
a = 100
*/