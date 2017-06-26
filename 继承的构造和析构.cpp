#include <iostream>
using namespace std;

class TEMP
{
private:
	int ta;
	int tb;
public:
	TEMP(int a, int b)
	{
		cout << "TEMP\tconstructor" << endl;
	}

	~TEMP()
	{
		cout << "TEMP\tdis-structor" << endl;
	}
};

class ONE
{
private:
	int oa;
	int ob;
	TEMP wc;
public:
	ONE(int a, int b):wc(a, b)
	{
		cout << "ONE\tconstructor" << endl;
	}

	~ONE()
	{
		cout << "ONE\tdis-structor" << endl;
	}
};

class TWO :public ONE
{

private:
	int wa;
	int wb;
	TEMP wc;
public:
	TWO(int a, int b, int c, int d, int e, int f):ONE(c, d), wc(e, f)
	{
		cout << "TWO\tconstructor" << endl;
	}

	~TWO()
	{
		cout << "TWO\tdis-structor" << endl;
	}
};

int main(void)
{
	TWO fabu(1, 2, 3, 4, 5, 6);
	return 0;
}

/*
输出结果：
TEMP    constructor
ONE     constructor
TEMP    constructor
TWO     constructor
TWO     dis-structor
TEMP    dis-structor
ONE     dis-structor
TEMP    dis-structor

分析：
构造函数调用顺序：基类->类成员对象->派生类，如果基类中也有类成员对象，那么就先构造类成员对象
析构函数调用顺序相反
*/