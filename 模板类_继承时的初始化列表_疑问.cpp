
#include <iostream>
using namespace std;

template <typename T>
class Concrete
{
public:
	T a;
	Concrete(T a)
	{
		this->a = a;
	}
};

class Derive : public Concrete<int>//模板类派生正常子类
{
public:
	Derive(int a) :Concrete<int> (a), b(1)
	{
		b = a;
	}
	Concrete<int> b;//按int继承
};

template <typename R> 
class Derive2 :public Concrete<R>//模板类派生模板类
{
public:
	R t;
	Concrete g;	//这里的g对象类属是什么？？？？？？？？？？？？
				//是R吗？？？
	Derive2(R a, int b) :Concrete<R> (a), g(a)
	{
		this->t = a;
	}
};

int main(void)
{
	Derive c(10);
	Concrete<double> d(20);
	Derive2<int> e(1, 2);
	cout << "Compelete" << endl;;
	return 0;
}
