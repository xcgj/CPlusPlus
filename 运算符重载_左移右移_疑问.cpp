#include <iostream>
using namespace std;

class A
{
private:
	int s;
	friend istream& operator>>(istream& in, A &b);
public:
	int x, y;
	A(int x, int y)
	{
		this->x = x;
		this->y = y;//����д��y = y;
		cout << "����" << endl;
	}

	void prints()
	{
		cout << "s = " << s << endl;
	}
};

ostream& operator<<(ostream &out, A &a)//��������ֵ�䵱��ֵ����Ҫ����һ������//ȫ�ֺ���
{
	cout << "ȫ��" << a.x << " " << a.y << endl;
	return out;
}

istream& operator>>(istream& in, A &b)//��Ԫ����
{
	cin >> b.s;
	return in;
}

int main(void)
{
	A m(1, 2), n = A(3, 4);
	cout << m << n << "xcgj" << endl;//֧����ʽ���

	cin >> m >> n;	//֧����ʽ���
	m.prints();
	n.prints();

	return 0;
}

/*
�޷�ʵ�����Ա�����Ĳ��������أ�
ostream& operator<<(A &a)
{
	cout << "ȫ��" << a.x << " " << a.y << endl;
	return *this;
}û��ostream��Դ��
��������д����cout.operator<<(m);

���⣺��Ƶ4-15˵��Ԫ��������ʵ�֣����ʵ�֣�����
��:��ȫ�ֺ�������ΪA�����Ԫ��������A���˽�г�Ա

*/