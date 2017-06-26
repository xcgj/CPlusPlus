#include "iostream"
using std::cout;
using std::endl;

class A
{
private:
	int a;
	friend void fa(A*, int);	//友元函数
public:
	A(int x)
	{
		this->a = x;
		cout << "a = " << this->a << endl;
	}
	~A()
	{
		cout << "析构" << endl;
	}
public:
	void printA()
	{
		cout << "a = " << this->a << endl;
	}
	friend void fb(A*, int);	//友元函数
};

void fa(A *m, int j)
{
	m->a = j;
}

void fb(A *n, int k)
{
	n->a = k;
}

int main(void)
{
	A g(5);
	fa(&g, 100);
	g.printA();
	fb(&g, 200);
	g.printA();
	return 0;
}