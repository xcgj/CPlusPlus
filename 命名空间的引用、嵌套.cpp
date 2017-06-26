#include "iostream"
namespace XCGJ
{
	int a = 1;
}

namespace RBMW
{
	int a = 2;
	namespace C01	//命名空间嵌套
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
		RBMW::C01::A test;	//结构体引入方法1
		cout << test.a << endl;
	}

	{
		using RBMW::C01::A;
		A test1;	//结构体引入方法2
		cout << test1.a << endl;
	}
}