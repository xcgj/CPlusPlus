#include "iostream"
using namespace std;

class constr
{							//构造函数一般用来初始化类的属性
public:
	constr()				//无参数构造函数
	{
		x = 0;
		y = 0;
	}

	constr(int a, int b)	//有参数构造函数1
	{
		x = a;
		y = b;
	}

	constr(int a)			//有参数构造函数2
	{
		x = a;
		y = 10;
	}

	constr(constr &ex)		//赋值构造函数（拷贝构造函数）
	{
		x = ex.x + 100;
		y = ex.y + 100;
	}

	void Print()
	{
		cout << "x: " << x << "\ty: " << y << endl;
	}

	~constr()				//析构函数
	{
	}
private:
	int x;
	int y;
};


void Invoke(constr ex)		//此处没有引用,//赋值构造函数（拷贝构造函数）	方法3
{
	ex.Print();				//从实参获得拷贝
}

constr test()				//函数将返回一个匿名对象，是否保留匿名对象（不析构）取决于接收方式
{
	constr ex(50, 60);
	return ex;				//此处会先执行一个拷贝构造函数，创建一个匿名对象，再析构原来的对象ex（局部变量）
}

int main(void)		//对象初始化方法
{	//默认
	constr ex0;				//调用了无参数构造函数
	ex0.Print();
	//括号法
	constr ex1(22, 33);		//调用了有参数构造函数1
	ex1.Print();

	constr ex6(ex1);		//赋值构造函数（拷贝构造函数）		方法2
	ex6.Print();

	//等号法
	constr ex2 = (1, 3, 5, 7, 9);//逗号表达式，调用有参构造函数2
	ex2.Print();

	constr ex3 = 5;			//调用有参构造函数2
	ex3.Print();

	constr ex5 = ex1;		//赋值构造函数（拷贝构造函数）	方法1
	ex5.Print();

	//手动调用构造函数
	constr ex4 = constr(2, 3);//调用了有参数构造函数1，匿名对象初始化
	ex4.Print();

	constr ex7;
	ex7 = ex1;				//这是赋值操作，不是初始化，不会调用构造函数
	ex7.Print();

	Invoke(ex1);			//用实参ex1去初始化形参ex，会调用拷贝函数

	constr ex8 = test();	//用匿名对象初始化ex8，匿名对象直接投胎在ex8上，不析构
	ex8.Print();			//赋值构造函数（拷贝构造函数）	方法4-1

	constr ex9(7, 8);
	ex9 = test();			//用匿名对象对ex9赋值操作，操作完成  后  ，匿名对象被编译器析构
	ex9.Print();			//赋值构造函数（拷贝构造函数）	方法4-2

	return 0;
}