#include <iostream>
using namespace std;

class Virtual
{
public:
	virtual void print(int) = 0;	//int�������Կ���ռλ�������β�
};

class Derive :public Virtual		//�̳г��������ʵ�� ���麯����������������
{
public:
	virtual void print(int a)
	{
		cout << "derive" << endl;
	}
};

//Virtual test(){}					//�����Ե���������ֵ�����麯��δ����
//void test(Virtual){}				//�����Ե��������������麯��δ����
Virtual& test(Virtual&) {}			//Ϊʲô���Ե�������ֵ���ú͵�������������

int main(void)
{
	Derive a;
	//Virtual b;					//�����Զ�����󣬴��麯��δ���塣�����಻�ܱ�ʵ����
	Virtual *c;						//Ϊʲô���Զ���ָ��
	return 0;
}

/*
���ۣ�
����ָ�벻����++�ķ�ʽ��������������飬����������ʹ�С��һ�����������
*/