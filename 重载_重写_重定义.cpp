#include <iostream>
using namespace std;

class A
{
public:
	virtual int func()
	{

	}
	int func(int a)
	{

	}
	int func(int a, int b)
	{

	}
	//����������func����������
};

class B :public A
{
	virtual int func()	//���func()�����Ƕ���A��func()��������д����̬��
	{

	}

	int func(int a)		//���func(int a)�����Ƕ���A��func(int a)�����ĵ���д���ض��壩
	{

	}
};

int main(void)
{

}

/*
���ۣ�
���أ�������ͬһ�������涨����ͬ������
��д��������������֮��
	�飨virtual����������д���Ƕ�̬
	�����麯������д�����ض���
*/