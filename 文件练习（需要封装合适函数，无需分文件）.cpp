#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[20];
	int age;
}student;
//1��ѭ������ṹ����Ϣ��������ageС��0ʱ�����������
//2����ѯ�����û���Ϣ
//3������Ҫɾ����������Ȼ����ļ�����Ӧ�����ֵĽṹɾ��
//4��������ʹ�õڶ����ļ���ֻ��һ���ļ�������������
//5����Ҫʹ�õ��ļ����Ĳ�������fwrite��fread

int Input()
{
	int res = 0;
	student temp;
	FILE *p = fopen("stu.txt", "wb");

	while (1)
	{
		printf("������ѧ�����䣬���븺���˳�д��\n");//��ȡ����
		scanf("%d", &temp.age);
		if (temp.age < 0)
		{
			fclose(p);
			printf("stu.txt �ѱ���\n");
			return res;
		}

		memset(temp.name, 0, sizeof(temp.name));//����������
		printf("������ѧ��������\n");//��ȡ����
		scanf("%s", temp.name);
		
		fwrite(&temp, sizeof(student), 1, p);
	}
}

int List()
{
	int res = 0;
	student temp;
	FILE *p = fopen("stu.txt", "rb");

	memset(&temp, 0, sizeof(student));
	while ((res = fread(&temp, sizeof(student), 1, p)) != 0)
	{
		printf("%s, %d\n", temp.name, temp.age);
		memset(&temp, 0, sizeof(student));
	}

	fclose(p);
	return 0;
}

int Search()
{
	int res = 0;
	student temp;

	FILE *p = fopen("stu.txt", "rb");
	printf("������Ҫ���ҵ�����:");
	char buf[20];
	scanf("%s", buf);

	int flag = 1;
	memset(&temp, 0, sizeof(student));
	while (res = fread(&temp, sizeof(student), 1, p) != 0)
	{
		if (strcmp(buf, temp.name) == 0)
		{
			printf("%s, %d\n", temp.name, temp.age);
			flag = 0;
		}
	}

	if (flag)
	{
		printf("���޴���\n");
	}
	return res;
}

int Delete()
{
	int res = 0;
	student temp;

	FILE *p = fopen("stu.txt", "rb+");
	printf("������Ҫɾ��������:");
	char buf[20];
	scanf("%s", buf);
	int num = 0;
	while ((res = fread(&temp, sizeof(student), 1, p)) != 0)//����ı�������
	{
		num++;
	}

	fseek(p, 0, SEEK_SET);
	student *pt = (student*)calloc(num, sizeof(student));//����ռ�
	fread(pt, sizeof(student), num, p);//һ�ζ�������
	fclose(p);

	int flag = 1;
	p = fopen("stu.txt", "wb");
	for (int i = 0; i < num; i++)
	{
		if (strcmp(buf, pt[i].name) == 0)
		{
			flag = 0;
			printf("��Ϣ %s,%d ��ɾ��\n", pt[i].name, pt[i].age);
			continue;//ƥ�䵽
		}
		fwrite(pt + i, sizeof(student), 1, p);
		//printf("%s, %d\n", (pt + i)->name, (pt + i)->age);
	}

	if (flag)
	{
		printf("���޴���\n");
	}

	fclose(p);
	printf("stu.txt �ѱ���\n");
	free(pt);
	return 0;
}

int Clear()
{
	system("cls");//windows��������
	return 0;
}

void menu()
{
	printf("**************************\n");
	printf("* 1 ������Ϣ\n");
	printf("* 2 ��ѯ��Ϣ\n");
	printf("* 3 ɾ���û�\n");
	printf("* 4 �����Ļ\n");
	printf("* 5 �г�����\n");
	printf("* 6 �˳�����\n");
	printf("**************************\n");
}

void modify()
{
	int(*p[])() = {Input, Search, Delete, Clear, List};//����ָ������
	int n = sizeof(p) / sizeof(p[0]);

	while (1)
	{
		menu();
		int cmd = 0;
		scanf("%d", &cmd);
		if (cmd >= 1 && cmd <= n)
		{
			p[cmd - 1]();
		}
		else if (cmd == 6)
			break;
		else
			printf("�������������룺");
	}
}

int main(void)
{
	modify();
	printf("Compelete\n");
	return 0;
}