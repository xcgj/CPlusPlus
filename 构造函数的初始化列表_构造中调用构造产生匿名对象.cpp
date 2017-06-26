#include "iostream"
using namespace std;

class H
{
public:
	H(int x, int y, int m)
	{
		i = x;
		j = y;
		k = m;
		cout << "构造" << i << j << k << endl;
	}

	H(int x, int y)
	{
		i = x;
		j = y;
		
		H(x, y, 100);//此处会产生一个匿名对象，由于没有接收，生命周期只在这一行
	}

	~H()
	{
		cout << "析构h" << i << endl;
	}

private:
	int i;
	int j;
	int k;
};

void test()
{
	H a(1, 2);
}

int main(void)
{
	test();
	return 0;
}
