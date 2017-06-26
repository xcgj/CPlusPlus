#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<typename T>
class Concrete
{
public:
	Concrete(T a, T b);					//���캯��
	void Print();						//��Ա����
	Concrete operator+(Concrete & obj);	//����������
	friend ostream& operator<<		<T>		(ostream& a, Concrete & obj);//���Ʋ���������
private:
	T a;
	T b;
};

template<typename T>
Concrete<T>::Concrete(T a, T b)			//���캯��ʵ��
{
	this->a = a;
	this->b = b;
}

template<typename T>
void Concrete<T>::Print()				//��Ա����
{
	cout << /*this->*/a << "��" << /*this->*/b << endl;
}

template <typename T>
Concrete<T> Concrete<T>::operator+(Concrete<T> & obj)//����������
//����ֵ���;��廯                  �������;��廯
{
	Concrete tmp(a + obj.a, b + obj.b);
	//Concrete <T>   tmp(a + obj.a, b + obj.b);//�ɼӿɲ��ӣ��Ѿ��ں����ڲ���
	return tmp;
}

template <typename T>
ostream& operator<<(ostream& a, Concrete<T> & obj)//���Ʋ���������
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
