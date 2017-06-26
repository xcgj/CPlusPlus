#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Fruit2
{
public:
	virtual void Kind() = 0;
};

class peach : public Fruit2
{
public:
	virtual void Kind()
	{
		cout << "peach" << endl;
	}
};



class apple : public Fruit2
{
public:
	virtual void Kind()
	{
		cout << "apple" << endl;
	}
};

class Factory
{
public:
	//生产出子类（具体水果类）的实例，返回给父类（水果类）指针调用，实现多态
	Fruit2 * Creat(const char * s)//获得要生产的指令
	{
		if (strcmp(s, "peach") == 0)
		{
			return (new peach);
		}
		else if (strcmp(s, "apple") == 0)
		{
			return (new apple);
		}
		else
		{
			cout << "无法识别" << endl;
			return NULL;
		}
	}
	//可扩展性很差，每次增加新水果都需要重新写这个函数，增加新内容
};


int main(void)
{
	//定义父类指针
	Fruit2 * fruit = NULL;

	//定义工厂对象，等待生产指令
	Factory * factory = new Factory;

	//接收指令
	fruit = factory->Creat("peach");
	//相应指令
	fruit->Kind();
	delete fruit;

	//接收指令
	fruit = factory->Creat("apple");
	//相应指令
	fruit->Kind();
	delete fruit;

	delete factory;
	cout << "Compelete" << endl;;
	return 0;
}

/*
实现思路
具体水果类继承了抽象水果类，实现虚函数重写
具体水果类需要一个工厂生产实例，返回值是水果类，实现多态

最后用父类（水果类）指针调用虚函数实现多态（具体水果类的虚函数重写）
*/
