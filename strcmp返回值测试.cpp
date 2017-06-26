#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

int main(void)
{
	cout << strcmp("111", "1111") << endl;	//	-1
	cout << strcmp("111", "11") << endl;	//	1
	cout << strcmp("211", "1111") << endl;	//	1
	cout << strcmp("ab", "aa") << endl;		//	1
	cout << strcmp("aaa", "aa") << endl;	//	1
	cout << strcmp("aA", "aa") << endl;		//	-1
	return 0;
}

/*
结论：
参数1字符大返回1
字符一样，参数1长度长返回1
*/