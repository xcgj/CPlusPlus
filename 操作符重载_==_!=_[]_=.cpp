#include <iostream>
#include <ctime>
using namespace std;

class X
{
private:
	int m;
	int *arr;
public:
	X(int x)	//分配堆空间
	{
		if (x < 0)
			x = 0;
		m = x;
		arr = new int[m];
		cout << "new done" << endl;
	}

	~X()	//释放堆空间
	{
		delete[] arr;
		cout << "delete done" << endl;
	}

	int& operator[](int i)
	{
		return arr[i];	//返回引用，不能返回元素，左操作数必须为左值
	}

	X& operator=(X &c)
	{
		if (this->arr != NULL)	//重新分配空间
			delete[] arr;
		this->m = c.m;
		this->arr = new int[this->m];
		int i = 0;
		for (; i < this->m; i++)	//元素赋值
			(*this)[i] = c[i];		//巧用 [] 重载
		return *this;
	}

	bool operator==(X &c)
	{
		if (this->m != c.m)	//重新分配空间
			return false;
		int i = 0;
		for (; i < this->m; i++)	//元素赋值
		{
			if ((*this)[i] != c[i])	//巧用 [] 重载
				return false;
		}
		return true;
	}

	bool operator!=(X &c)
	{
		return !(*this == c);
	}
};


int main(void)
{
	int num = 10;
	X a(num);

	srand((unsigned int)time(NULL));//种子
	int i = 0;
	for (; i < num; i++)
		a[i] = rand() % num;	//随机赋值

								//X b = a;	//赋值构造函数（拷贝构造函数)，浅拷贝，X(const X& c)
	X b = 0;

	cout << "b==a " << (b == a) << endl;
	cout << "b!=a " << (b != a) << endl;

	b = a;

	for (i = 0; i < num; i++)
	{
		cout << "a[" << i << "] = " << b[i] << endl;
	}

	cout << "b==a " << (b == a) << endl;
	cout << "b!=a " << (b != a) << endl;

	return 0;
}

//注意点：函数返回值必须为左值