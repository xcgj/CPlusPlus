/*
重写配置文件写功能
a) 课堂上的例子，临时数据是放在栈区数组，然后关闭文件，再把临时数据重新写入文件
b) 将临时数组放在堆区，堆区大小不是一次性就分配好，而是通过realloc分配，慢慢增加

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*
	int len = strlen(buf);	每读取一次的字符串长度
	size += len;	堆区要申请的总大小
	char * temp = (char *)realloc(size + len + 1, sizeof(char));
	if(temp == NULL){...}
	strcat(temp, p);
	strcat(temp, buf);
	temp[size + len] = '\0';	c风格字符串
	p = temp;
	*/
	printf("Compelete\n");
	return 0;
}
