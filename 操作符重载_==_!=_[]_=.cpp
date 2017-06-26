#include <iostream>
#include <ctime>
using namespace std;

class X
{
private:
	int m;
	int *arr;
public:
	X(int x)	//����ѿռ�
	{
		if (x < 0)
			x = 0;
		m = x;
		arr = new int[m];
		cout << "new done" << endl;
	}

	~X()	//�ͷŶѿռ�
	{
		delete[] arr;
		cout << "delete done" << endl;
	}

	int& operator[](int i)
	{
		return arr[i];	//�������ã����ܷ���Ԫ�أ������������Ϊ��ֵ
	}

	X& operator=(X &c)
	{
		if (this->arr != NULL)	//���·���ռ�
			delete[] arr;
		this->m = c.m;
		this->arr = new int[this->m];
		int i = 0;
		for (; i < this->m; i++)	//Ԫ�ظ�ֵ
			(*this)[i] = c[i];		//���� [] ����
		return *this;
	}

	bool operator==(X &c)
	{
		if (this->m != c.m)	//���·���ռ�
			return false;
		int i = 0;
		for (; i < this->m; i++)	//Ԫ�ظ�ֵ
		{
			if ((*this)[i] != c[i])	//���� [] ����
				return false;
		}
		return true;
	}

	bool operator!=(X &c)
	{
		return !(*this == c);
	}
};


int main(void)
{
	int num = 10;
	X a(num);

	srand((unsigned int)time(NULL));//����
	int i = 0;
	for (; i < num; i++)
		a[i] = rand() % num;	//�����ֵ

								//X b = a;	//��ֵ���캯�����������캯��)��ǳ������X(const X& c)
	X b = 0;

	cout << "b==a " << (b == a) << endl;
	cout << "b!=a " << (b != a) << endl;

	b = a;

	for (i = 0; i < num; i++)
	{
		cout << "a[" << i << "] = " << b[i] << endl;
	}

	cout << "b==a " << (b == a) << endl;
	cout << "b!=a " << (b != a) << endl;

	return 0;
}

//ע��㣺��������ֵ����Ϊ��ֵ