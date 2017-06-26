#include <iostream>
using namespace std;

class A
{
public:
	int *p;
	static int a;
	A()
	{
		a++;
		p = new int[10];
		cout << "构造A, a = " << a << endl;
	}

	virtual ~A()
	{
		delete[] p;
		cout << "析构A, a = " << a << endl;
	}
};

class B :public A
{
public:
	int *p;
	B()
	{
		p = new int[10];
		cout << "构造B" << endl;
	}

	~B()
	{
		delete[] p;
		cout << "析构B" << endl;
	}
};

class C :public B
{
public:
	int *p;
	C()
	{
		p = new int[10];
		cout << "构造C" << endl;
	}

	~C()
	{
		delete[] p;
		cout << "析构C" << endl;
	}
};

int A::a = 0;

void test1(A *m)
{
	delete m;
}

void test2(A *m)
{
	;
	//delete m;	//不能delete，实参指针不是new来的
}

int main(void)
{
	A *pA = new C;	//开辟一个存放 类C 的存储空间，返回一个指向该存储空间的地址(即指针)
	//C a;
	//pA = &a;
	test1(pA);

	cout << "--------------" << endl;
	C b;
	A *pB = &b;
	test2(pB);

	cout << "--------------" << endl;
	A *pC = new C;
	delete pC;

	cout << "--------------" << endl;
	C *pD = new C;
	delete pD;
	return 0;
}

/*
结果输出(A类析构函数不加virtual关键字)：直接删除 指向派生类的对象的内存空间 会造成内存泄露
构造A, a = 1		//pA					
构造B			//pA					
构造C			//pA					
析构A, a = 1		//pA					
--------------							
构造A, a = 2		//pB					
构造B			//pB					
构造C			//pB					
--------------							
构造A, a = 3		//pC					
构造B			//pC					
构造C			//pC					
析构A, a = 3		//pC					
--------------							
构造A, a = 4		//pD					
构造B			//pD					
构造C			//pD					
析构C			//pD	正常析构			
析构B			//pD	正常析构			
析构A, a = 4		//pD	正常析构			
析构C			//pB	正常析构			
析构B			//pB	正常析构			
析构A, a = 4		//pB	正常析构			
										
结果输出(A类析构函数加virtual关键字)：全部能正常析构
构造A, a = 1		//pA
构造B			//pA
构造C			//pA
析构C			//pA
析构B			//pA
析构A, a = 1	    //pA
--------------
构造A, a = 2		//pB
构造B			//pB
构造C			//pB
--------------
构造A, a = 3		//pC
构造B			//pC
构造C			//pC
析构C			//pC
析构B			//pC
析构A, a = 3	    //pC
--------------
构造A, a = 4		//pD
构造B			//pD
构造C			//pD
析构C			//pD
析构B			//pD
析构A, a = 4	    //pD
析构C			//pB
析构B			//pB
析构A, a = 4	    //pB

结论：
通过父类指针删除堆空间才需要使用 virtual 关键字将 父类的析构函数 变成 虚析构函数
如果删除派生类的空间，不需要使用虚析构函数
*/