#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//题解
//先求总长度分配空间
//两个指针，一个用来strcat，一个用来检查空格

int dellSpace(char **p)
{
	int res = 0;
	if (p == NULL || *p == NULL)
	{
		res = -1;
		fprintf(stderr, "dellSpace NULL pointer\n");
		return res;
	}

	char *p2 = *p;
	int len = strlen(p2);
	char *p1 = (char*)calloc(len + 1, sizeof(char));

	int newlen = 0;
	while(*p2)
	{
		if (!(isspace(*p2)))
		{
			strncat(p1, p2, 1);
			newlen++;
		}
		p2++;
	}

	p1[newlen] = '\0';
	*p = p1;
	
	return res;
}

int main(void)
{
	char s[100] = " a	 d we ";
	char *p = s;
	dellSpace(&p);
	printf("%s", p);
	free(p);
	return 0;
}
