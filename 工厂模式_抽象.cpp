#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//==============������==============//

class Fruit	//ˮ����
{
public:
	virtual void Kind() = 0;
};

class Vegta	//�߲���
{
public:
	virtual void name() = 0;
};

class AbFactory	//���󹤳��࣬�����õ�����ʵ�����ظ�ˮ�������
{
public:
	virtual Fruit * Creat() = 0;
	virtual Vegta * VCreat() = 0;
};//��Ʒ���಻���Ͽ���ԭ�򣬲�Ʒ���ط���


//==============��Ʒ��==============//

class Northpeach : public Fruit	//�����࣬�̳г���ˮ���࣬�麯����д
{
public:
	virtual void Kind()
	{
		cout << "Northpeach" << endl;
	}
};

class Northpotato : public Vegta
{
public:
	virtual void name()
	{
		cout << "Northpotato" << endl;
	}
};




class Southpeach : public Fruit	//�����࣬�̳г���ˮ���࣬�麯����д
{
public:
	virtual void Kind()
	{
		cout << "Southpeach" << endl;
	}
};

class Southpotato : public Vegta
{
public:
	virtual void name()
	{
		cout << "Southpotato" << endl;
	}
};


//==============������==============//

class North :public AbFactory	//���ӹ�����������������ʵ�����̳г��󹤳����Ա㷵��ʵ����ˮ�������
{
public:
	virtual Fruit * Creat()
	{
		return (new Northpeach);//��������ʵ��
	}

	virtual Vegta * VCreat()
	{
		return (new Northpotato);
	}
};



class South : public AbFactory
{
public:
	virtual Vegta * VCreat()
	{
		return (new Southpotato);
	}

	virtual Fruit * Creat()
	{
		return (new Southpeach);
	}
};

/*
����չ����2�������1������
*/

int main(void)
{
	Fruit * fruit = NULL;
	Vegta * vegta = NULL;
	AbFactory * factory = NULL;

	//=============����===============//

	factory = new North;//���๤��ָ�����๤��
	fruit = factory->Creat();//�������ú�������ʵ��������ֵ��֪ˮ����
	fruit->Kind();
	vegta = factory->VCreat();//�������ú�������ʵ��������ֵ��֪�߲���
	vegta->name();
	delete fruit;
	delete vegta;
	delete factory;


	//==============�Ϸ�==============//

	factory = new South;//���๤��ָ�����๤��
	fruit = factory->Creat();//�������ú�������ʵ��������ֵ��֪ˮ����
	fruit->Kind();
	vegta = factory->VCreat();//�������ú�������ʵ��������ֵ��֪�߲���
	vegta->name();
	delete fruit;
	delete vegta;
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