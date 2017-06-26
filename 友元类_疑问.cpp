#include "iostream"
using std::cout;
using std::endl;

class A;
class B;

//友元类通常设计为一种辅助类，用来传递数据操作或类之间的消息
class A
{
	friend class B;	//声明 B 是 A 的友元类
	//int bx;		//声明无效，bx 不是类 B 中的 bx
	//void btest();	//声明无效，只能在类中访问友元的私有成员
private:
	int ax;
	int ay;
	void atest()
	{
		cout << "this is A's private function" << endl;
	}
public:
	B fb;			//文件 line 5 已经声明类 B ，为什么还会报错？？？问题若解决验证结论2
	void aprint()
	{
		fb.btest();	//A没有在B中声明是B的友元类，访问B的私有函数失败
		//fb.bx;		//A没有在B中声明是B的友元类，访问B的私有成员失败
		//fb.by;		//A没有在B中声明是B的友元类，访问B的私有成员失败
		cout << "友元类的声明是单向的，不是双向的" << endl;
	}
};

class B
{
	friend class A;
private:
	int bx;
	int by;
	void btest()
	{
		cout << "this is B's private function" << endl;
	}
	A fa;
	//B d;			无法定义d，测试能否用d访问A的私有成员---应该不行
public:
	void SetVal(int a, int b)
	{
		this->fa.ax = a;
		fa.ay = b;
	}
	void bprint()
	{
		fa.atest();
		cout << "ax = " << fa.ax << endl;
		cout << "ay = " << fa.ay << endl;
		cout << "在B中用A的对象访问了A的私有成员" << endl;
	}
};

void test()
{
	A a;
	B b;
	//a.btest();	//声明无效，只能在类中访问友元的私有成员
}

int main(void)
{
	B set;
	set.SetVal(10, 20);
	set.bprint();
	return 0;		//传递数据操作或类之间的消息，而没有写类 A
}

/*
结论：
1 友元类有限定：只能在类中访问友元的私有成员
2 友元类的声明是单向的，不是双向的，B在A中声明友元，B在A中不能访问A的私有成员？ 待验证
3 友元类通常设计为一种辅助类，用来传递数据操作或类之间的消息
*/