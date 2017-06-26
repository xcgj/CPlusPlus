#include "iostream"
using namespace std;

class A
{
public:
	A(int a, int b, int c)
	{
		r = a;
		s = b;
		t = c;
		cout << "A����" << r << s << t << endl;
	}

	~A()
	{
		cout << "A����" << r << s << t << endl;
	}

private:
	int r, s, t;
};

class H
{
public:
	H(int x, int y, int m) : q(1, 2, 3), w(4, 5, 6)
	{
		i = x;
		j = y;
		k = m;
		cout << "H����" << i << j << k << endl;
	}

	H(H &abc) : q(7, 8, 9), w(10, 11, 12)
	{
		cout << "H��ֵ����" << i << j << k << endl;
	}

	~H()
	{
		cout << "H����" << i << j << k << endl;
	}

private:
	int i;
	int j;
	int k;
	A w;
	A q;
};


void test2(H g)
{
	cout << "test2 end" << endl;
}

void test()
{
	H a(9, 8, 7);
	test2(a);
	cout << "test end" << endl;
}

int main(void)
{
	test();
	return 0;
}
/*
A����456		//�ȵ���Ա����w�Ĺ���
A����123		//�ٵ���Ա����q�Ĺ���
H����987		//H����Ĺ��캯��		//֮��a���캯��������ɣ��ߵ�test2�����������β�g�ĸ�ֵ���캯������
A����101112	//����Ա����w�Ĺ���
A����789		//����Ա����q�Ĺ���
H��ֵ����-8589934601572718418575062	//H����Ĺ��캯��
test2 end	//test2��������
H����-8589934601572718418575062		//�������������������
A����789		
A����101112
test end
H����987
A����123
A����456
*/