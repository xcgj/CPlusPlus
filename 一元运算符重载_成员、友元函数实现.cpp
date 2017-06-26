#include "iostream"
using namespace std;

class D
{
	int a;
public:
	friend D& operator++(D &q);
	friend D operator++(D &q, int);
	D(int i)
	{
		this->a = i;
	}

	void print()
	{
		cout << a << endl;
	}

	D& operator--()
	{
		this->a--;
		cout << "ǰ��--" << endl;
		return *this;
	}

	D operator--(int)
	{
		D temp = *this;
		this->a--;
		cout << "����--" << endl;
		return temp;
	}
};

D& operator++(D &q)
{
	q.a++;
	cout << "ǰ��++" << endl;
	return q;
}

D operator++(D &q, int)//����������ã�����temp����������ַ��Ч
{
	D temp = q;
	q.a++;
	cout << "����++" << endl;
	return temp;//������ʱ������ȥ����
}

int main(void)
{
	D x = 3, y(5), z = D(6);
	operator++(x);	//��Ԫ����
	x.print();
	++x;			//����������
	x.print();
	y.operator--();	//��Ա����
	y.print();
	--y;			//����������
	y.print();
	operator++(z, 0);//��Ԫ����������2��㣬ֻҪ��int
	z.print();
	z++;			//����������
	z.print();
	z.operator--(1);//��Ա������������㣬ֻҪ��int
	z.print();
	z--;			//����������
	z.print();
	return 0;
}

/*
����ԭ�ͣ�
void operator<<(ostream &out, A *this);
void operator<<(ostream &out, A &a);
*/