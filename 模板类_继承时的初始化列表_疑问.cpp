
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

class Derive : public Concrete<int>//ģ����������������
{
public:
	Derive(int a) :Concrete<int> (a), b(1)
	{
		b = a;
	}
	Concrete<int> b;//��int�̳�
};

template <typename R> 
class Derive2 :public Concrete<R>//ģ��������ģ����
{
public:
	R t;
	Concrete g;	//�����g����������ʲô������������������������
				//��R�𣿣���
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
