#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Fruit	//ˮ����
{
public:
	virtual void Kind() = 0;
};

class AbFactory	//���󹤳��࣬�����õ�����ʵ�����ظ�ˮ�������
{
public:
	virtual Fruit * Creat() = 0;
};

class peach : public Fruit	//�����࣬�̳г���ˮ���࣬�麯����д
{
public:
	virtual void Kind()
	{
		cout << "peach" << endl;
	}
};

class peachFactory :public AbFactory	//���ӹ�����������������ʵ�����̳г��󹤳����Ա㷵��ʵ����ˮ�������
{
public:
	virtual Fruit * Creat()
	{
		return (new peach);//��������ʵ��
	}
};

/*
����չ����ˮ���������Ӧ�Ĺ���
*/

int main(void)
{
	Fruit * fruit = NULL;
	AbFactory * factory = NULL;

	factory = new peachFactory;//���๤��ָ�����๤��
	fruit = factory->Creat();//�������ú�������ʵ��������ֵ��֪ˮ����
	fruit->Kind();
	delete fruit;
	delete factory;

	cout << "Compelete" << endl;;
	return 0;
}

/*
ʵ��˼·
����ˮ����̳��˳���ˮ���࣬ʵ���麯����д
����ˮ������Ҫһ����������ʵ��������ֵ��ˮ���࣬ʵ�ֶ�̬
Ϊ�˿���չ�ԣ���Ҫ�����һ���ܵĹ����࣬ͳһ���غ�������ֵ
������չʱ����Ҫд����ˮ���ࣨ�̳��ڳ���ˮ���ࣩ�;��幤���ࣨ�̳��ڳ��󹤳��ࣩ
����ʱ��
	���󹤳���ָ�����๤����ʵ����
	�ٵ��ú���������һ������ˮ�����ʵ��
	�ó���ˮ����ȥ�����ʵ���ķ���ֵ����ʱ������ˮ����ָ��������ˮ����ʵ��
	����ø��ࣨˮ���ָࣩ������麯��ʵ�ֶ�̬������ˮ������麯����д��
*/