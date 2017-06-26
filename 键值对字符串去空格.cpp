/*
��ֵ�ԣ�"key = value"���ַ������ڿ����о���ʹ��
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ
Ҫ��2����д��������
Ҫ��3����ֵ���м������n��ո���ȥ���ո�

�ο��⺯����strncpy(), strlen(), strstr(), ����ʹ��sscanf()����

���ܣ�
��ֵ�ԣ���key = value�����ַ������Ӽ�key���Ҷ�Ӧ��ֵvalue
������
keyval����ֵ�ԣ���key = value�����ַ���
pkey����
buf��ƥ�������Ӧ������
len��ƥ�������Ӧ���ݵĳ���
����ֵ��
�ɹ���0
ʧ�ܣ���0


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

	// ��"key1 =    valude1"�в���"key1"ƥ����ַ�����
	//����ҵ�����ȡ=������ַ���������ȥ������ո�
	int ret = getKeyByValue("key1 =       ", "key1", buf, &len);
	//���ú�����buf="valude1", len=7

	printf("buf=%s,len=%d\n", buf, len);

	return 0;
}

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf/*out*/, int *valuebuflen/*out*/)
{
	int ret = 0;
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)//�жϿ�ָ��
	{
		ret = -1;
		fprintf(stderr, "keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL\n");
		return ret;
	}

	if (strstr(keyvaluebuf, keybuf) == NULL || strchr(keyvaluebuf, '=') == NULL)//�жϼ�ֵ�����Ƿ�����Ч�ļ�ֵ
	{
		ret = -2;
		fprintf(stderr, "invalid key&value\n");
		return ret;
	}

	char *pmid = strchr(keyvaluebuf, '=');	//ָ���˵Ⱥ��ַ����ڵĵ�ַ
	int val_len = strlen(pmid + 1);			//�Ⱥź����ַ����ĳ���
	char *pstart = pmid + 1;				//��ʼλ��

	int i = 0, j = val_len - 1;				//�±�
	int temp_i = 0, temp_j = 0;
	while (!temp_i || !temp_j)
	{
		if (!temp_i)						//��Ƿ���ָ������ǿ��ַ����÷�0���öδ����ں���ѭ������ִ��
		{
			if (!(isspace(*(pstart + i))))
				temp_i = i;					//��i���±�ǿվͰ�ֵ����temp_iȻ��ֹͣ�ԼӺ��ж�
			i++;
		}
		if (!temp_j)
		{
			if (!(isspace(*(pstart + j))))
				temp_j = j;
			j--;
		}
		if (j < 0)							//�����ַ������ǿո�
		{
			*valuebuflen = 0;
			valuebuf[*valuebuflen] = 0;				
			return ret;
		}
	}

	printf("%d,%d\n", temp_i, temp_j);
	*valuebuflen = temp_j - temp_i + 1;
	strncpy(valuebuf, pstart + temp_i, *valuebuflen);
	valuebuf[*valuebuflen] = 0;				//C����ַ���

	return ret;
}