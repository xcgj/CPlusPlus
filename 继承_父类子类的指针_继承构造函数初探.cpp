#include <iostream>
using namespace::std;

class Senior
{
public:
	void print1()
	{
		cout << "class senior" << endl;
	}

	Senior()
	{
		cout << "senior constructor func" << endl;
	}

	Senior(const Senior &a)
	{
		cout << "senior copy constructor func" << endl;
	}
};

class Young :public Senior
{
public:
	void print2()
	{
		cout << "class young" << endl;
	}

	Young()
	{
		cout << "Young constructor func" << endl;
	}

	Young(const Young &a)
	{
		cout << "Young copy constructor func" << endl;
	}
};

void func(Senior &d)
{
	cout << "func" << endl;
}

int main(void)
{

	Young a;
	a.print2();
	a.print1();		//���������Ե����������ʹ��

	Senior b;
	cout << "pause" << endl;
	b = a;			//����������ֱ�Ӹ�ֵ���������

	Senior c = a;	//����������ֱ�ӳ�ʼ���������

	Senior *p = NULL;
	p = &a;			//����ָ�����ֱ��ָ���������
	p->print1();

	//p->print2();	//����pָ��������Ǹ��࣬print2()���������չ���������Ǹ���ĺ���	//��̬
	func(a);		//�������ÿ���ֱ�������������

	return 0;
}

/*
������������
senior constructor func
Young constructor func		//˵���ڶ����������aʱ,�ȵ��ø��๹�캯��,�ٵ������๹�캯��
class young
class senior
senior constructor func		//�������bʱ����
senior copy constructor func//��ʼ���������c = a����ֵ���캯��
class senior
func
*/