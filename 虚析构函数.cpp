#include <iostream>
using namespace std;

class A
{
public:
	int *p;
	static int a;
	A()
	{
		a++;
		p = new int[10];
		cout << "����A, a = " << a << endl;
	}

	virtual ~A()
	{
		delete[] p;
		cout << "����A, a = " << a << endl;
	}
};

class B :public A
{
public:
	int *p;
	B()
	{
		p = new int[10];
		cout << "����B" << endl;
	}

	~B()
	{
		delete[] p;
		cout << "����B" << endl;
	}
};

class C :public B
{
public:
	int *p;
	C()
	{
		p = new int[10];
		cout << "����C" << endl;
	}

	~C()
	{
		delete[] p;
		cout << "����C" << endl;
	}
};

int A::a = 0;

void test1(A *m)
{
	delete m;
}

void test2(A *m)
{
	;
	//delete m;	//����delete��ʵ��ָ�벻��new����
}

int main(void)
{
	A *pA = new C;	//����һ����� ��C �Ĵ洢�ռ䣬����һ��ָ��ô洢�ռ�ĵ�ַ(��ָ��)
	//C a;
	//pA = &a;
	test1(pA);

	cout << "--------------" << endl;
	C b;
	A *pB = &b;
	test2(pB);

	cout << "--------------" << endl;
	A *pC = new C;
	delete pC;

	cout << "--------------" << endl;
	C *pD = new C;
	delete pD;
	return 0;
}

/*
������(A��������������virtual�ؼ���)��ֱ��ɾ�� ָ��������Ķ�����ڴ�ռ� ������ڴ�й¶
����A, a = 1		//pA					
����B			//pA					
����C			//pA					
����A, a = 1		//pA					
--------------							
����A, a = 2		//pB					
����B			//pB					
����C			//pB					
--------------							
����A, a = 3		//pC					
����B			//pC					
����C			//pC					
����A, a = 3		//pC					
--------------							
����A, a = 4		//pD					
����B			//pD					
����C			//pD					
����C			//pD	��������			
����B			//pD	��������			
����A, a = 4		//pD	��������			
����C			//pB	��������			
����B			//pB	��������			
����A, a = 4		//pB	��������			
										
������(A������������virtual�ؼ���)��ȫ������������
����A, a = 1		//pA
����B			//pA
����C			//pA
����C			//pA
����B			//pA
����A, a = 1	    //pA
--------------
����A, a = 2		//pB
����B			//pB
����C			//pB
--------------
����A, a = 3		//pC
����B			//pC
����C			//pC
����C			//pC
����B			//pC
����A, a = 3	    //pC
--------------
����A, a = 4		//pD
����B			//pD
����C			//pD
����C			//pD
����B			//pD
����A, a = 4	    //pD
����C			//pB
����B			//pB
����A, a = 4	    //pB

���ۣ�
ͨ������ָ��ɾ���ѿռ����Ҫʹ�� virtual �ؼ��ֽ� ������������� ��� ����������
���ɾ��������Ŀռ䣬����Ҫʹ������������
*/