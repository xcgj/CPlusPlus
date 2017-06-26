#include "iostream"
using namespace std;
#include "Teacher.h"
//using namespace std;

int main(void) 
{
	int x = 10;
	const int &y = x;//常引用
	x = 100;
	Teacher t1;//类调用
	int z = t1.MaxCom(x, y);
	cout << "z:" << z << endl;
	return 0;
}