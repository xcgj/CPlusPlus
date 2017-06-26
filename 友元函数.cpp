#include "iostream"
using std::cout;
using std::endl;

class A
{
private:
	int a;
	friend void fa(A*, int);	//��Ԫ����
public:
	A(int x)
	{
		this->a = x;
		cout << "a = " << this->a << endl;
	}
	~A()
	{
		cout << "����" << endl;
	}
public:
	void printA()
	{
		cout << "a = " << this->a << endl;
	}
	friend void fb(A*, int);	//��Ԫ����
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