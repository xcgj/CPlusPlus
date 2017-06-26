#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Concrete
{
public:
	virtual void Salary() = 0;
protected:
private:
};

class Primary : public Concrete
{
public:
	Primary()
	{
		name = new char[1];
		name = strcpy(name, "");
		salary = 0;
		cout << "Primary construct compelete" << endl;
	}

	~Primary()
	{
		delete[] name;
		name = NULL;
		salary = 0;
		cout << "Primary destruct compelete" << endl;
	}

	void GetInf(char *s, int a)
	{
		if (s == NULL)
			s = "";
		int len = strlen(s) + 1;
		if (name != NULL)
			delete[] name;
		name = new char[len];
		this->name = strncpy(name, s, len);
		this->salary = a;
	}

	virtual void Salary()
	{
		cout << "name = " << name << ", salary = " << salary << endl;
	}
protected:
private:
	char *name;
	int salary;
};

class Senior : public Concrete
{
public:
	Senior()
	{
		name = new char[1];
		name = strcpy(name, "");
		salary = 0;
		cout << "Senior construct compelete" << endl;
	}

	~Senior()
	{
		delete[] name;
		name = NULL;
		salary = 0;
		cout << "Senior destruct compelete" << endl;
	}

	void GetInf(char *s, int a)
	{
		if (s == NULL)
			s = "";
		int len = strlen(s) + 1;
		if (name != NULL)
			delete[] name;
		name = new char[len];
		this->name = strncpy(name, s, len);
		this->salary = a;
	}

	virtual void Salary()
	{
		cout << "name = " << name << ", salary = " << salary << endl;
	}
protected:
private:
	char *name;
	int salary;
};

void Port(Concrete &a)	//函数封装接口，父类调用子类实现的接口，纯虚函数+多态
{
	a.Salary();
}

int main(void)
{
	Primary a;
	a.GetInf("lilei", 10000);
	Port(a);

	Senior b;
	b.GetInf("hanmeimei", 20000);
	Port(b);

	cout << "Compelete" << endl;;
	return 0;
}