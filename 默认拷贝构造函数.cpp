#include "iostream"
using namespace std;

class A
{
public:
	A(int a)
	{
		r = a;
		cout << "A����" << r << endl;
	}

	A(const A &a)
	{
		this->r = a.r;
		cout << "A��ֵ����" << r << endl;
	}

	~A()
	{
		cout << "A����" << r << endl;
	}

	void print()
	{
		cout << "r " << this->r << endl;
	}
private:
	int r;
};


int main(void)
{
	A a(10);
	A b = a;
	b.print();
	return 0;
}

/*
A����10
A��ֵ����10	//û��Ĭ�ϸ�ֵ���캯��
r 10
A����10
A����10
*/