#include "iostream"
using std::cin;
using std::cout;
using std::endl;

class A
{
public:
	int a;
	A(int m = 0)
	{
		a = m;
		cout << "����" << a << endl;
	}
	A(const A &abc)
	{
		this->a = abc.a;
		cout << "��ֵ����" << a << endl;
	}
	A calc(A &ano)	//��Ա������������A * const this�� void calc(A * const this, A ano)
	{				//���⣺���ĳ�A& calc(A &ano)����ʱ��������������𣿣���������������������������ʱ�ڴ��ڲ���ʾ
		A temp(this->a + ano.a);
		cout << "calc" << temp.a << endl;
		return temp;	//����temp��������������
	}
	~A()
	{
		cout << "����" << a << endl;
	}
};

A& Gcalc(A *a1, A &a2)	//ȫ�ֺ���,������������	//�������ã�a3�����������������������󣡣���
{
	A a3(33);
	a3.a = a1->a + a2.a;
	cout << "ȫ�ֺ������ý���" << endl;
	return a3;
}



int main(void)
{
	A m(1), n(2);
	A t;
	t = m.calc(n);	//��Ա���������������ֵ���Ƹ�t��������������
	A g = Gcalc(&m, n);	//ȫ�ֺ���	//�������������������
	cout << "���������ý���" << endl;
	return 0;
}
/*
����1	//m
����2	//n
����0	//t
����3	//temp
calc3
��ֵ����3	//��Ա���� ��������
����3	//temp
����3	//��Ա���� ��������
����33	//a3
ȫ�ֺ������ý���
����3	//a3������
��ֵ���죿	//ȫ�ֺ��� ��������	//����
���������ý���
������	//ȫ�ֺ��� ��������->g	//����
����3
����2
����1
*/