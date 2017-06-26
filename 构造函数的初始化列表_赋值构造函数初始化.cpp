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
		cout << "A构造" << r << s << t << endl;
	}

	~A()
	{
		cout << "A析构" << r << s << t << endl;
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
		cout << "H构造" << i << j << k << endl;
	}

	H(H &abc) : q(7, 8, 9), w(10, 11, 12)
	{
		cout << "H赋值构造" << i << j << k << endl;
	}

	~H()
	{
		cout << "H析构" << i << j << k << endl;
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
A构造456		//先调成员对象w的构造
A构造123		//再调成员对象q的构造
H构造987		//H自身的构造函数		//之后a构造函数调用完成，走到test2函数，进入形参g的赋值构造函数调用
A构造101112	//调成员对象w的构造
A构造789		//调成员对象q的构造
H赋值构造-8589934601572718418575062	//H自身的构造函数
test2 end	//test2函数调用
H析构-8589934601572718418575062		//作用域结束，对象析构
A析构789		
A析构101112
test end
H析构987
A析构123
A析构456
*/