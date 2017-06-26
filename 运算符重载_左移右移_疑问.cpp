#include <iostream>
using namespace std;

class A
{
private:
	int s;
	friend istream& operator>>(istream& in, A &b);
public:
	int x, y;
	A(int x, int y)
	{
		this->x = x;
		this->y = y;//不能写成y = y;
		cout << "构造" << endl;
	}

	void prints()
	{
		cout << "s = " << s << endl;
	}
};

ostream& operator<<(ostream &out, A &a)//函数返回值充当座值，需要返回一个引用//全局函数
{
	cout << "全局" << a.x << " " << a.y << endl;
	return out;
}

istream& operator>>(istream& in, A &b)//友元函数
{
	cin >> b.s;
	return in;
}

int main(void)
{
	A m(1, 2), n = A(3, 4);
	cout << m << n << "xcgj" << endl;//支持链式编程

	cin >> m >> n;	//支持链式编程
	m.prints();
	n.prints();

	return 0;
}

/*
无法实现类成员函数的操作符重载：
ostream& operator<<(A &a)
{
	cout << "全局" << a.x << " " << a.y << endl;
	return *this;
}没有ostream的源码
函数调用写法：cout.operator<<(m);

问题：视频4-15说友元函数可以实现，如何实现？？？
答:将全局函数定义为A类的友元函数访问A类的私有成员

*/