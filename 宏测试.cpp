#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//	__FILE__			宏所在文件的源文件名 
//	__LINE__			宏所在行的行号
//	__DATE__			代码编译的日期
//	__TIME__			代码编译的时间

int main(void)
{

	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__ - 2);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);

	return 0;
}