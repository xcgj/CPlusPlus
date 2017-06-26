#include "iostream"
using std::cout;
using std::endl;

class A;
class B;

//��Ԫ��ͨ�����Ϊһ�ָ����࣬�����������ݲ�������֮�����Ϣ
class A
{
	friend class B;	//���� B �� A ����Ԫ��
	//int bx;		//������Ч��bx ������ B �е� bx
	//void btest();	//������Ч��ֻ�������з�����Ԫ��˽�г�Ա
private:
	int ax;
	int ay;
	void atest()
	{
		cout << "this is A's private function" << endl;
	}
public:
	B fb;			//�ļ� line 5 �Ѿ������� B ��Ϊʲô���ᱨ�����������������֤����2
	void aprint()
	{
		fb.btest();	//Aû����B��������B����Ԫ�࣬����B��˽�к���ʧ��
		//fb.bx;		//Aû����B��������B����Ԫ�࣬����B��˽�г�Աʧ��
		//fb.by;		//Aû����B��������B����Ԫ�࣬����B��˽�г�Աʧ��
		cout << "��Ԫ��������ǵ���ģ�����˫���" << endl;
	}
};

class B
{
	friend class A;
private:
	int bx;
	int by;
	void btest()
	{
		cout << "this is B's private function" << endl;
	}
	A fa;
	//B d;			�޷�����d�������ܷ���d����A��˽�г�Ա---Ӧ�ò���
public:
	void SetVal(int a, int b)
	{
		this->fa.ax = a;
		fa.ay = b;
	}
	void bprint()
	{
		fa.atest();
		cout << "ax = " << fa.ax << endl;
		cout << "ay = " << fa.ay << endl;
		cout << "��B����A�Ķ��������A��˽�г�Ա" << endl;
	}
};

void test()
{
	A a;
	B b;
	//a.btest();	//������Ч��ֻ�������з�����Ԫ��˽�г�Ա
}

int main(void)
{
	B set;
	set.SetVal(10, 20);
	set.bprint();
	return 0;		//�������ݲ�������֮�����Ϣ����û��д�� A
}

/*
���ۣ�
1 ��Ԫ�����޶���ֻ�������з�����Ԫ��˽�г�Ա
2 ��Ԫ��������ǵ���ģ�����˫��ģ�B��A��������Ԫ��B��A�в��ܷ���A��˽�г�Ա�� ����֤
3 ��Ԫ��ͨ�����Ϊһ�ָ����࣬�����������ݲ�������֮�����Ϣ
*/