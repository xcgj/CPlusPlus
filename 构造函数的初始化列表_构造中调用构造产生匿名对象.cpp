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
		cout << "����" << i << j << k << endl;
	}

	H(int x, int y)
	{
		i = x;
		j = y;
		
		H(x, y, 100);//�˴������һ��������������û�н��գ���������ֻ����һ��
	}

	~H()
	{
		cout << "����h" << i << endl;
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
