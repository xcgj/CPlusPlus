#include "iostream"
using namespace std;

class D
{
	int a;
public:
	friend D& operator++(D &q);
	friend D operator++(D &q, int);
	D(int i)
	{
		this->a = i;
	}

	void print()
	{
		cout << a << endl;
	}

	D& operator--()
	{
		this->a--;
		cout << "前置--" << endl;
		return *this;
	}

	D operator--(int)
	{
		D temp = *this;
		this->a--;
		cout << "后置--" << endl;
		return temp;
	}
};

D& operator++(D &q)
{
	q.a++;
	cout << "前置++" << endl;
	return q;
}

D operator++(D &q, int)//如果返回引用，由于temp被析构，地址无效
{
	D temp = q;
	q.a++;
	cout << "后置++" << endl;
	return temp;//返回临时变量拿去运算
}

int main(void)
{
	D x = 3, y(5), z = D(6);
	operator++(x);	//友元函数
	x.print();
	++x;			//操作符重载
	x.print();
	y.operator--();	//成员函数
	y.print();
	--y;			//操作符重载
	y.print();
	operator++(z, 0);//友元函数，参数2随便，只要是int
	z.print();
	z++;			//操作符重载
	z.print();
	z.operator--(1);//成员函数，参数随便，只要是int
	z.print();
	z--;			//操作符重载
	z.print();
	return 0;
}

/*
函数原型：
void operator<<(ostream &out, A *this);
void operator<<(ostream &out, A &a);
*/