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
		s = new char[len + 1];// +1 ������β��\0
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
		else if (len < b.len)//�ͷžɿռ䣬Ҳ���Բ��жϣ�ֱ���ͷ�������
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
	A m(x), n, w = "��ɪasdx";
	n = m = w;	//m������a���Ƹ�n������a
	n.print();
	m.print();
	w.print();
	return 0;
}
/*
��Ļ�������=���Ǵ����������㣩
constructor 1
constructor 2
constructor 1
deep copy done
deep copy done
s = ��ɪasdx
s = ��ɪasdx
s = ��ɪasdx
disstructor
disstructor
disstructor

���ۣ�
1 ����ǰ���ͷžɵĶ��ڴ棬��ֹ�ڴ��ַ��ʧ���ڴ�й©
2 ��������������
*/