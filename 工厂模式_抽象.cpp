#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//==============抽象类==============//

class Fruit	//水果类
{
public:
	virtual void Kind() = 0;
};

class Vegta	//蔬菜类
{
public:
	virtual void name() = 0;
};

class AbFactory	//抽象工厂类，将所得到具体实例返回给水果类调用
{
public:
	virtual Fruit * Creat() = 0;
	virtual Vegta * VCreat() = 0;
};//产品种类不符合开闭原则，产品产地符合


//==============产品线==============//

class Northpeach : public Fruit	//桃子类，继承抽象水果类，虚函数重写
{
public:
	virtual void Kind()
	{
		cout << "Northpeach" << endl;
	}
};

class Northpotato : public Vegta
{
public:
	virtual void name()
	{
		cout << "Northpotato" << endl;
	}
};




class Southpeach : public Fruit	//桃子类，继承抽象水果类，虚函数重写
{
public:
	virtual void Kind()
	{
		cout << "Southpeach" << endl;
	}
};

class Southpotato : public Vegta
{
public:
	virtual void name()
	{
		cout << "Southpotato" << endl;
	}
};


//==============生产线==============//

class North :public AbFactory	//桃子工厂，负责生产桃子实例，继承抽象工厂，以便返回实例供水果类调用
{
public:
	virtual Fruit * Creat()
	{
		return (new Northpeach);//产生桃子实例
	}

	virtual Vegta * VCreat()
	{
		return (new Northpotato);
	}
};



class South : public AbFactory
{
public:
	virtual Vegta * VCreat()
	{
		return (new Southpotato);
	}

	virtual Fruit * Creat()
	{
		return (new Southpeach);
	}
};

/*
可扩展其他2个种类和1个工厂
*/

int main(void)
{
	Fruit * fruit = NULL;
	Vegta * vegta = NULL;
	AbFactory * factory = NULL;

	//=============北方===============//

	factory = new North;//父类工厂指向子类工厂
	fruit = factory->Creat();//工厂调用函数生产实例，返回值告知水果类
	fruit->Kind();
	vegta = factory->VCreat();//工厂调用函数生产实例，返回值告知蔬菜类
	vegta->name();
	delete fruit;
	delete vegta;
	delete factory;


	//==============南方==============//

	factory = new South;//父类工厂指向子类工厂
	fruit = factory->Creat();//工厂调用函数生产实例，返回值告知水果类
	fruit->Kind();
	vegta = factory->VCreat();//工厂调用函数生产实例，返回值告知蔬菜类
	vegta->name();
	delete fruit;
	delete vegta;
	delete factory;

	cout << "Compelete" << endl;;
	return 0;
}

/*
实现思路
具体水果类继承了抽象水果类，实现虚函数重写
具体水果类需要一个工厂生产实例，返回值是水果类，实现多态
为了可扩展性，需要抽象出一个总的工厂类，统一返回函数返回值
新增扩展时，需要写具体水果类（继承于抽象水果类）和具体工厂类（继承于抽象工厂类）
调用时，
抽象工厂类指向子类工厂的实例，
再调用函数创建出一个具体水果类的实例
用抽象水果类去接这个实例的返回值，此时，抽象水果类指向了子类水果的实例
最后用父类（水果类）指针调用虚函数实现多态（具体水果类的虚函数重写）
*/