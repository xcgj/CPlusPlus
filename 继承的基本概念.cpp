#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Concrete
{
public:
	int a;
	void fun()
	{
		b = 0;
	}
protected://��������������ʹ�ã�������������ⲿʹ��
	int b = 10;
private:
	int c;
};

class Derive_1:public Concrete
{
public:
	int m;
	void fun()
	{
		a = 0;
		b = 0;
		//c = 0;	�����޷�����
	}
};

class Derive_2 :protected Concrete
{
public:
	int m;
	void fun()
	{
		a = 0;
		//b = 0;
		//c = 0;	�����޷�����
	}
};

class Derive_3 :private Concrete
{
public:
	int m;
	void fun()
	{
		a = 0;
		b = 0;
		//c = 0;	�����޷�����
	}

};

class Dederive_2 :protected Derive_2
{
public:
	void func()
	{
		cout << "b = " << b << endl;
	}
};

int main(void)
{
	Derive_1 x;
	Derive_2 y;
	Derive_3 z;
	x.a;	//�޷����ʻ����˽������c���Լ�b����

	Dederive_2 g;
	g.func();	//protected��μ̳У���Ȼ��Ч

	return 0;
}

/*
���ۣ�
1 public�̳У����������������б���ԭ�з��ʼ���
2 protected�̳У����ʸ����public���Ա�Ϊprotected�����಻��
3 private�̳У����ʸ����ȫ�����ԣ�������private
4 �������ּ̳з�ʽ�������˽�г�Ա������ֱ�ӱ���������ʣ���ȴ����������������ռ��
5 protected�ؼ�����ר�����ڼ̳еģ�����ļ�����ʹ��
6 ��Ŀ����һ����public�̳У����������protect

�ж�ĳһ�仰���ܷ񱻷���
1����������䣬��仰д��������ڲ����ⲿ
2����������δӸ���̳У�public��private��protected��
3���������еķ��ʼ���public��private��protected��

						
�̳з�ʽ		||	public		proteced	private		<--�����Ա���ʿ��Ƽ���
			||
public		||	public		proteced	private		<--���ʼ���
proteced	||	proteced	proteced	private		<--���ʼ���
private		||	private		private		private		<--���ʼ���


*/