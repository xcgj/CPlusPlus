#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//1 �����������Ԫ����
template <typename T>
class Concrete;
template <typename T>
Concrete<T> myadd(Concrete<T> & a, Concrete<T> & b);

//2 ������
template <typename T>
class Concrete
{
public:
	//3 �ڲ�����
	friend Concrete myadd   <T>   (Concrete & a, Concrete & b);
	//friend Concrete<T> myadd   <T>   (Concrete<T> & a, Concrete<T> & b);//ͬ��

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

//4 �ⲿʵ��
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
	//5 ����
	Concrete<int> z = myadd<int>(x, y);
	z.Print();
	cout << "Compelete" << endl;;
	return 0;
}