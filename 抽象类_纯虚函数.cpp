#include <iostream>
using namespace std;

class Virtual
{
public:
	virtual void print(int) = 0;	//int参数可以看成占位符或者形参
};

class Derive :public Virtual		//继承抽象类必须实现 纯虚函数，否则定义对象出错
{
public:
	virtual void print(int a)
	{
		cout << "derive" << endl;
	}
};

//Virtual test(){}					//不可以当函数返回值，纯虚函数未定义
//void test(Virtual){}				//不可以当函数参数，纯虚函数未定义
Virtual& test(Virtual&) {}			//为什么可以当作返回值引用和当作参数的引用

int main(void)
{
	Derive a;
	//Virtual b;					//不可以定义对象，纯虚函数未定义。抽象类不能被实例化
	Virtual *c;						//为什么可以定义指针
	return 0;
}

/*
结论：
父类指针不能用++的方式操作子类对象数组，如果数据类型大小不一样，程序崩溃
*/