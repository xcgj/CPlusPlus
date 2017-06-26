#include "iostream"
using namespace std;

class F
{
	int a;
	int b;
	friend F operator+(F &, F &);
public:
	F(int m = 0, int n = 0)
	{
		this->a = m;
		this->b = n;
	}
	void print()
	{
		cout << a << "+" << b << "i" << endl;
	}
};

F operator+(F &x, F &y)
{
	return F(x.a + y.a, x.b + y.b);
}

int main(void)
{
	F i = F(10, 20);
	F j(i);
	F k = i + j;
	k.print();
	return 0;
}