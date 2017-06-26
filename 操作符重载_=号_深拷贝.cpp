#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
 
class A
{
	char *s = NULL;
	int len;
public:
	A(char *a)
	{
		if (a == NULL)
			exit(-1);
		len = strlen(a);
		s = new char[len + 1];// +1 拷贝结尾的\0
		strcpy(s, a);
		cout << "constructor 1" << endl;
	}

	A(int i = 0)
	{
		cout << "constructor 2" << endl;
	}

	~A()
	{
		if (s != NULL)
		{
			delete[] s;
			s = NULL;
		}
		cout << "disstructor" << endl;
	}

	A& operator=(const A &b)
	{
		if (s == NULL)
		{
			this->len = b.len;
			this->s = new char[len + 1];
		}
		else if (len < b.len)//释放旧空间，也可以不判断，直接释放再申请
		{
			delete[] this->s;
			this->len = b.len;
			this->s = new char[len + 1];
		}

		strcpy(this->s, b.s);
		cout << "deep copy done" << endl;
		return *this;
	}

	void print()
	{
		cout << "s = " << s << endl;
	}

};

int main(void) 
{
	char *x = "xcgj";
	A m(x), n, w = "阿瑟asdx";
	n = m = w;	//m的属性a复制给n的属性a
	n.print();
	m.print();
	w.print();
	return 0;
}
/*
屏幕输出：（=号是从右往左运算）
constructor 1
constructor 2
constructor 1
deep copy done
deep copy done
s = 阿瑟asdx
s = 阿瑟asdx
s = 阿瑟asdx
disstructor
disstructor
disstructor

结论：
1 拷贝前先释放旧的堆内存，防止内存地址丢失，内存泄漏
2 函数返回是引用
*/