#include <iostream>
using namespace std;

class Concrete
{
public:
	int a;
};

class C1 :virtual public Concrete	//虚继承加 virtual，用在父类和祖父类之间
{
public:
	int b;
};

class C2 :virtual public Concrete	//虚继承加 virtual，用在父类和祖父类之间
{
public:
	int c;
};

class C3 : public Concrete	//虚继承加 virtual，用在父类和祖父类之间
{
public:
	int c;
};

class A :public C1, public C2	//正常方式继承
{
public:
	int d;
};

int main(void)
{
	A test;
	//test.a = 100;	//不可访问间接虚拟基类“Concrete”
	test.b = 100;
	test.c = 200;
	test.d = 300;

	cout << "sizeof C2 =" << sizeof(C2) << endl;	//12	//加了virtual关键字会给变量隐式增加属性
	cout << "sizeof C3 =" << sizeof(C3) << endl;	//8
	
	return 0;
}