#if 0
/*
* ����һ���Ѿ�������������������һ������
* �������в�����������ʹ�����ǵĺ�������������Ǹ�����
* ����ж�����ֵĺ͵�����������֣��������һ�Լ���
* �����������飺1,2,4,7,11,15 �� ����15������ 4+11=15���������4��11
*/
#endif
#include <stdio.h>
#include <string.h>
#if 0
/*
* ����һ���ַ�����������е�һ�γ��ֵĲ��ظ����ַ�
* ����: ���� aabccdebff ����� b
*/
#endif

void foo4()
{
	char *s = "aadbcceff";
	int len = strlen(s);
	//O(n2)
	/*for (int i = 0; i < len; ++i)
	{
		int flag = 1;
		for (int j = 0; j < len; ++j)
		{
			if (i == j)
				continue;
			if (s[i] == s[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			printf("%c\n", s[i]);
			break;
		}
		else
		{
			continue;
		}
	}*/

	int num[26] = { 0 };
	int index[26] = { 0 };
	for (int i = 0; i < len; ++i)
	{
		++num[s[i] - 'a'];//��¼�ַ����ִ���
		index[s[i] - 'a'] = i;//��¼�ַ����һ�γ��ֵ�λ��
	}
	int min = len;
	for (int i = 0; i < 26; ++i)
	{
		if (num[i]/*�ַ����ִ���*/ == 1&&index[i]/*�ַ����ֵ�λ��*/<min)
		{
			min = index[i];
		}
	}
	printf("%c\n", s[min]);
}

#if 0
/*
* ʵ��һ��ʮ����ת�����Ƶĺ���������һ��ʮ���������Զ�������ʽ���
* void dec2bin(int n);
*/
#endif 

void dec2bin(int n)
{
	for (int i = 31; i >= 0; --i)
	{
		printf("%d", n >> i & 1);
	}
}

/*
 * ��������������ֵ�ļ��ַ���
 */

void foo1()
{
	int a = 5;
	int b = 3;
	/*int temp = a;   �˷ѿռ�
	a = b;
	b = temp;*/

	//1,3,5,6,3,1
	/*a = a^b;    
	b = a^b;
	a = a^b;*/
	
	/*
	
	a = 4��	 //ע�⣺ͬһ�����������0�������
	a = a^a;   
	a = a^a;
	a = a^a;
	--------------
	0100
	0100
	0000
	-----------------
	0000
	0100
	0100
	---------------
	0100
	0100
	0000
	*/

	//a = a + b; //5+3=8  �������
	//b = a - b; //8-3=5
	//a = a - b; //8-5=3  

	//a = a - b; //5-3=2
	//b = a + b; //2+3=5
	//a = b - a; //5-2=3
}

void foo2()
{
	//O()
	//int arr[1024]={1,2,3,4....,1024}
	//10
	//arr[9]  O(1);
	//����  O(n);
	//ѭ��Ƕ�� O(n^2)
	//���ַ� O(logN);
}

void foo3()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int n = 11;
	//O(n2)
	/*for (int i = 0; i < 8; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (arr[i] + arr[j] == n)
			{
				printf("n=%d,arr[i]=%d,arr[j]=%d\n", n, arr[i], arr[j]);
				return;
			}
		}
	}*/

	int begin = 0;
	int end = 8;
	while (begin < end)
	{
		if (arr[begin] + arr[end] > n)
		{
			--end;
		}
		else if (arr[begin] + arr[end] < n)
		{
			++begin;
		}
		else
		{
			printf("n=%d,arr[i]=%d,arr[j]=%d\n", n, arr[begin], arr[end]);
			return;
		}
	}
}

int main()
{
	//foo3();
	//foo4();
	dec2bin(15);
}