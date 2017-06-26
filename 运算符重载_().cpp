#include <iostream>
using namespace std;

class A
{
	int a;
public:
	A(int x)
	{
		a = x;
		cout << "a = " << a << endl;
	}

	int operator()(int m, int n)
	{
		a = m * n / (m + n);
		//cout << "operator ()" << a << endl;
		return a;
	}
};

int main(void)
{
	A d(0);
	cout << "d() = " << d(200, 300) << endl;
	return 0;
}