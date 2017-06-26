#include "iostream"
using namespace std;

class constr
{							//���캯��һ��������ʼ���������
public:
	constr()				//�޲������캯��
	{
		x = 0;
		y = 0;
	}

	constr(int a, int b)	//�в������캯��1
	{
		x = a;
		y = b;
	}

	constr(int a)			//�в������캯��2
	{
		x = a;
		y = 10;
	}

	constr(constr &ex)		//��ֵ���캯�����������캯����
	{
		x = ex.x + 100;
		y = ex.y + 100;
	}

	void Print()
	{
		cout << "x: " << x << "\ty: " << y << endl;
	}

	~constr()				//��������
	{
	}
private:
	int x;
	int y;
};


void Invoke(constr ex)		//�˴�û������,//��ֵ���캯�����������캯����	����3
{
	ex.Print();				//��ʵ�λ�ÿ���
}

constr test()				//����������һ�����������Ƿ����������󣨲�������ȡ���ڽ��շ�ʽ
{
	constr ex(50, 60);
	return ex;				//�˴�����ִ��һ���������캯��������һ����������������ԭ���Ķ���ex���ֲ�������
}

int main(void)		//�����ʼ������
{	//Ĭ��
	constr ex0;				//�������޲������캯��
	ex0.Print();
	//���ŷ�
	constr ex1(22, 33);		//�������в������캯��1
	ex1.Print();

	constr ex6(ex1);		//��ֵ���캯�����������캯����		����2
	ex6.Print();

	//�Ⱥŷ�
	constr ex2 = (1, 3, 5, 7, 9);//���ű��ʽ�������вι��캯��2
	ex2.Print();

	constr ex3 = 5;			//�����вι��캯��2
	ex3.Print();

	constr ex5 = ex1;		//��ֵ���캯�����������캯����	����1
	ex5.Print();

	//�ֶ����ù��캯��
	constr ex4 = constr(2, 3);//�������в������캯��1�����������ʼ��
	ex4.Print();

	constr ex7;
	ex7 = ex1;				//���Ǹ�ֵ���������ǳ�ʼ����������ù��캯��
	ex7.Print();

	Invoke(ex1);			//��ʵ��ex1ȥ��ʼ���β�ex������ÿ�������

	constr ex8 = test();	//�����������ʼ��ex8����������ֱ��Ͷ̥��ex8�ϣ�������
	ex8.Print();			//��ֵ���캯�����������캯����	����4-1

	constr ex9(7, 8);
	ex9 = test();			//�����������ex9��ֵ�������������  ��  ���������󱻱���������
	ex9.Print();			//��ֵ���캯�����������캯����	����4-2

	return 0;
}