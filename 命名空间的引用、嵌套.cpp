#include "iostream"
namespace XCGJ
{
	int a = 1;
}

namespace RBMW
{
	int a = 2;
	namespace C01	//�����ռ�Ƕ��
	{
		int a = 3;
		struct A 
		{
			int a = 4;
		};
	}
}

void main_4()
{
	using namespace std;
	using namespace XCGJ;
	cout << a << endl;
	cout << RBMW::a << endl;
	cout << RBMW::C01::a << endl;

	{
		RBMW::C01::A test;	//�ṹ�����뷽��1
		cout << test.a << endl;
	}

	{
		using RBMW::C01::A;
		A test1;	//�ṹ�����뷽��2
		cout << test1.a << endl;
	}
}