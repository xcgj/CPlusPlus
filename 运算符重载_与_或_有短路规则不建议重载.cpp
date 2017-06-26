#include <iostream>
using std::cout;
using std::endl;

class A
{
private:
	int m, n;
public:
	A(int j, int k)
	{
		m = j, n = k;	//逗号表达式
	}

	A operator+(A &z)
	{
		cout << "+重载运算符被运行" << this->m + z.m << "  " << this->n + z.n << endl;
		return A(this->m + z.m, this->n + z.n);	//返回元素
	}

	bool operator&&(A &x)
	{
		cout << "&&重载运算符被运行" << endl;
		return (this->m + this->n) && (x.m + x.n);
	}

	bool operator||(A &y)
	{
		cout << "||重载运算符被运行" << endl;
		return (this->m + this->n) || (y.m + y.n);
	}
};

int main(void)
{
	A a(1, -1), b(2, 3);
	cout << "a && (a + b) = " << ((a + a) && (a + b)) << endl;
	//期望：先运行a+a，a+b不被运行
	cout << "a || (a + b) = " << ((a + a) || (a + b)) << endl;
	//期望：先运行a+a，再运行a+b
}
/*
输出结果：
+重载运算符被运行3  2		//a+b
+重载运算符被运行2  -2	//a+a
&&重载运算符被运行
a && (a + b) = 0
+重载运算符被运行3  2		//a+b
+重载运算符被运行2  -2	//a+a
||重载运算符被运行
a || (a + b) = 1

以上并未实现短路规则，因此不建议重载 && 和 ||
*/