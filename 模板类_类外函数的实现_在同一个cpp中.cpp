#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<typename T>
class Concrete
{
public:
	Concrete(T a, T b);					//构造函数
	void Print();						//成员函数
	Concrete operator+(Concrete & obj);	//操作符重载
	friend ostream& operator<<		<T>		(ostream& a, Concrete & obj);//左移操作符重载
private:
	T a;
	T b;
};

template<typename T>
Concrete<T>::Concrete(T a, T b)			//构造函数实现
{
	this->a = a;
	this->b = b;
}

template<typename T>
void Concrete<T>::Print()				//成员函数
{
	cout << /*this->*/a << "和" << /*this->*/b << endl;
}

template <typename T>
Concrete<T> Concrete<T>::operator+(Concrete<T> & obj)//操作符重载
//返回值类型具体化                  参数类型具体化
{
	Concrete tmp(a + obj.a, b + obj.b);
	//Concrete <T>   tmp(a + obj.a, b + obj.b);//可加可不加，已经在函数内部了
	return tmp;
}

template <typename T>
ostream& operator<<(ostream& a, Concrete<T> & obj)//左移操作符重载
{
	a << obj.a;
	return a;
}


int main(void)
{
	int x = 9;
	int y = 8;
	Concrete<int> z(x, y);
	z.Print();

	Concrete<int> zz(1, 1);
	Concrete<int> zzz = z + zz;
	zzz.Print();

	cout << z << endl;

	cout << "Compelete" << endl;;
	return 0;
}
