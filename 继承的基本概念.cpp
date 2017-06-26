#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Concrete
{
public:
	int a;
	void fun()
	{
		b = 0;
	}
protected://可以在派生类中使用，但不能在类的外部使用
	int b = 10;
private:
	int c;
};

class Derive_1:public Concrete
{
public:
	int m;
	void fun()
	{
		a = 0;
		b = 0;
		//c = 0;	报错，无法访问
	}
};

class Derive_2 :protected Concrete
{
public:
	int m;
	void fun()
	{
		a = 0;
		//b = 0;
		//c = 0;	报错，无法访问
	}
};

class Derive_3 :private Concrete
{
public:
	int m;
	void fun()
	{
		a = 0;
		b = 0;
		//c = 0;	报错，无法访问
	}

};

class Dederive_2 :protected Derive_2
{
public:
	void func()
	{
		cout << "b = " << b << endl;
	}
};

int main(void)
{
	Derive_1 x;
	Derive_2 y;
	Derive_3 z;
	x.a;	//无法访问基类的私有属性c，以及b属性

	Dederive_2 g;
	g.func();	//protected多次继承，仍然有效

	return 0;
}

/*
结论：
1 public继承：父类属性在子类中保持原有访问级别
2 protected继承：访问父类的public属性变为protected，其余不变
3 private继承：访问父类的全部属性，级别都是private
4 不论哪种继承方式，基类的私有成员都不能直接被派生类访问，但却存在于派生类里面占坑
5 protected关键字是专门用于继承的，在类的家族中使用
6 项目开发一般用public继承，特殊情况用protect

判断某一句话，能否被访问
1）看调用语句，这句话写在子类的内部、外部
2）看子类如何从父类继承（public、private、protected）
3）看父类中的访问级别（public、private、protected）

						
继承方式		||	public		proteced	private		<--父类成员访问控制级别
			||
public		||	public		proteced	private		<--访问级别
proteced	||	proteced	proteced	private		<--访问级别
private		||	private		private		private		<--访问级别


*/