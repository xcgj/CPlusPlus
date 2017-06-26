#include "iostream"
using namespace std;

class A
{
public:
	A(int a)
	{
		r = a;
		cout << "A构造" << r << endl;
	}

	A(const A &a)
	{
		this->r = a.r;
		cout << "A赋值构造" << r << endl;
	}

	~A()
	{
		cout << "A析构" << r << endl;
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
A构造10
A赋值构造10	//没有默认赋值构造函数
r 10
A析构10
A析构10
*/