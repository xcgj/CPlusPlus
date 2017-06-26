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
	A(int a = 0)	//����
	{
		if (a < 0)
			a = 0;
		c_a = a;
		c_p = new int[c_a];
		cout << "����" << endl;
	}

	~A()			//����
	{
		delete[] c_p;
		cout << "����" << endl;
	}
};

int main(void)
{
	A a1(5);		//�������
	a1.GetNum(20);	//��ֵ����
	a1.print();		//��ӡ����
	A a2;			//�������2
	a2.cpy(a1);		//���
	a2.print();
	return 0;
}

/*
����
number generate done
array[0] = 20
array[1] = 21
array[2] = 22
array[3] = 23
array[4] = 24
����
cpy done c_p = 010FFA3C
array[0] = 20
array[1] = 21
array[2] = 22
array[3] = 23
array[4] = 24
����					//������return����֮ǰ����
����
*/