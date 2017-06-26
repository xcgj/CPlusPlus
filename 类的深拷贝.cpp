#include "iostream"
using std::cout;
using std::endl;

class A
{
public:
	int c_a;
	int *c_p;

	void cpy(const A &obj)
	{
		this->c_a = obj.c_a;
		this->c_p = new int[this->c_a];
		int i = 0;
		for (; i < this->c_a; i++)
			this->c_p[i] = obj.c_p[i];
		cout << "cpy done c_p = " << &this->c_p << endl;
	}

	void GetNum(int origin = 0)
	{
		int i = 0;
		for (; i < this->c_a; i++)
			this->c_p[i] = origin++;
		cout << "number generate done" << endl;
	}

	void print()
	{
		int i = 0;
		for (; i < this->c_a; i++)
			cout << "array[" << i << "] = " << this->c_p[i] << endl;
	}

public:
	A(int a = 0)	//构造
	{
		if (a < 0)
			a = 0;
		c_a = a;
		c_p = new int[c_a];
		cout << "构造" << endl;
	}

	~A()			//析构
	{
		delete[] c_p;
		cout << "析构" << endl;
	}
};

int main(void)
{
	A a1(5);		//定义对象
	a1.GetNum(20);	//赋值对象
	a1.print();		//打印对象
	A a2;			//定义对象2
	a2.cpy(a1);		//深拷贝
	a2.print();
	return 0;
}

/*
构造
number generate done
array[0] = 20
array[1] = 21
array[2] = 22
array[3] = 23
array[4] = 24
构造
cpy done c_p = 010FFA3C
array[0] = 20
array[1] = 21
array[2] = 22
array[3] = 23
array[4] = 24
析构					//析构在return函数之前调用
析构
*/