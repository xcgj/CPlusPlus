#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//	__FILE__			�������ļ���Դ�ļ��� 
//	__LINE__			�������е��к�
//	__DATE__			������������
//	__TIME__			��������ʱ��

int main(void)
{

	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__ - 2);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);

	return 0;
}