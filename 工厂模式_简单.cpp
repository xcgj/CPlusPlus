#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Fruit2
{
public:
	virtual void Kind() = 0;
};

class peach : public Fruit2
{
public:
	virtual void Kind()
	{
		cout << "peach" << endl;
	}
};



class apple : public Fruit2
{
public:
	virtual void Kind()
	{
		cout << "apple" << endl;
	}
};

class Factory
{
public:
	//���������ࣨ����ˮ���ࣩ��ʵ�������ظ����ࣨˮ���ָࣩ����ã�ʵ�ֶ�̬
	Fruit2 * Creat(const char * s)//���Ҫ������ָ��
	{
		if (strcmp(s, "peach") == 0)
		{
			return (new peach);
		}
		else if (strcmp(s, "apple") == 0)
		{
			return (new apple);
		}
		else
		{
			cout << "�޷�ʶ��" << endl;
			return NULL;
		}
	}
	//����չ�Ժܲÿ��������ˮ������Ҫ����д�������������������
};


int main(void)
{
	//���常��ָ��
	Fruit2 * fruit = NULL;

	//���幤�����󣬵ȴ�����ָ��
	Factory * factory = new Factory;

	//����ָ��
	fruit = factory->Creat("peach");
	//��Ӧָ��
	fruit->Kind();
	delete fruit;

	//����ָ��
	fruit = factory->Creat("apple");
	//��Ӧָ��
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

����ø��ࣨˮ���ָࣩ������麯��ʵ�ֶ�̬������ˮ������麯����д��
*/
