#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//1 先声明类和友元函数
template <typename T>
class Concrete;
template <typename T>
Concrete<T> myadd(Concrete<T> & a, Concrete<T> & b);

//2 定义类
template <typename T>
class Concrete
{
public:
	//3 内部声明
	friend Concrete myadd   <T>   (Concrete & a, Concrete & b);
	//friend Concrete<T> myadd   <T>   (Concrete<T> & a, Concrete<T> & b);//同上

	Concrete(T b)
	{
		this->a = b;
	}

	void Print()
	{
		cout << "a = " << a << endl;
	}
protected:
private:
	T a;
};

//4 外部实现
template<typename T>
Concrete<T> myadd(Concrete<T> & a, Concrete<T> & b)
{
	Concrete<int> c(a.a + b.a);
	return c;
}

int main(void)
{
	Concrete<int> x(10);
	Concrete<int> y(20);
	//5 调用
	Concrete<int> z = myadd<int>(x, y);
	z.Print();
	cout << "Compelete" << endl;;
	return 0;
}