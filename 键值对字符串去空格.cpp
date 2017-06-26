/*
键值对（"key = value"）字符串，在开发中经常使用
要求1：请自己定义一个接口，实现根据key获取
要求2：编写测试用例
要求3：键值对中间可能有n多空格，请去除空格

参考库函数：strncpy(), strlen(), strstr(), 不能使用sscanf()函数

功能：
键值对（“key = value”）字符串更加键key查找对应的值value
参数：
keyval：键值对（“key = value”）字符串
pkey：键
buf：匹配键所对应的内容
len：匹配键所对应内容的长度
返回值：
成功：0
失败：非0


*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen);

int main(void)
{
	char buf[128] = { 0 };
	int len = 0;

	// 在"key1 =    valude1"中查找"key1"匹配的字符串，
	//如果找到，获取=后面的字符串，而且去掉多余空格
	int ret = getKeyByValue("key1 =       ", "key1", buf, &len);
	//调用函数后：buf="valude1", len=7

	printf("buf=%s,len=%d\n", buf, len);

	return 0;
}

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf/*out*/, int *valuebuflen/*out*/)
{
	int ret = 0;
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)//判断空指针
	{
		ret = -1;
		fprintf(stderr, "keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL\n");
		return ret;
	}

	if (strstr(keyvaluebuf, keybuf) == NULL || strchr(keyvaluebuf, '=') == NULL)//判断键值对中是否含有有效的键值
	{
		ret = -2;
		fprintf(stderr, "invalid key&value\n");
		return ret;
	}

	char *pmid = strchr(keyvaluebuf, '=');	//指向了等号字符所在的地址
	int val_len = strlen(pmid + 1);			//等号后面字符串的长度
	char *pstart = pmid + 1;				//起始位置

	int i = 0, j = val_len - 1;				//下标
	int temp_i = 0, temp_j = 0;
	while (!temp_i || !temp_j)
	{
		if (!temp_i)						//标记符在指针读到非空字符会置非0，该段代码在后续循环不再执行
		{
			if (!(isspace(*(pstart + i))))
				temp_i = i;					//第i个下标非空就把值赋给temp_i然后停止自加和判断
			i++;
		}
		if (!temp_j)
		{
			if (!(isspace(*(pstart + j))))
				temp_j = j;
			j--;
		}
		if (j < 0)							//整个字符串都是空格
		{
			*valuebuflen = 0;
			valuebuf[*valuebuflen] = 0;				
			return ret;
		}
	}

	printf("%d,%d\n", temp_i, temp_j);
	*valuebuflen = temp_j - temp_i + 1;
	strncpy(valuebuf, pstart + temp_i, *valuebuflen);
	valuebuf[*valuebuflen] = 0;				//C风格字符串

	return ret;
}