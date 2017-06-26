#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[20];
	int age;
}student;
//1、循环输入结构体信息，当输入age小于0时，则结束输入
//2、查询所有用户信息
//3、输入要删除的姓名，然后把文件中相应的名字的结构删除
//4、不可以使用第二个文件，只用一个文件来完成这个任务
//5、需要使用的文件核心操作函数fwrite、fread

int Input()
{
	int res = 0;
	student temp;
	FILE *p = fopen("stu.txt", "wb");

	while (1)
	{
		printf("请输入学生年龄，输入负数退出写入\n");//获取年龄
		scanf("%d", &temp.age);
		if (temp.age < 0)
		{
			fclose(p);
			printf("stu.txt 已保存\n");
			return res;
		}

		memset(temp.name, 0, sizeof(temp.name));//缓冲区清零
		printf("请输入学生姓名：\n");//获取名字
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
	printf("请输入要查找的姓名:");
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
		printf("查无此人\n");
	}
	return res;
}

int Delete()
{
	int res = 0;
	student temp;

	FILE *p = fopen("stu.txt", "rb+");
	printf("请输入要删除的姓名:");
	char buf[20];
	scanf("%s", buf);
	int num = 0;
	while ((res = fread(&temp, sizeof(student), 1, p)) != 0)//算出文本中人数
	{
		num++;
	}

	fseek(p, 0, SEEK_SET);
	student *pt = (student*)calloc(num, sizeof(student));//分配空间
	fread(pt, sizeof(student), num, p);//一次读完名单
	fclose(p);

	int flag = 1;
	p = fopen("stu.txt", "wb");
	for (int i = 0; i < num; i++)
	{
		if (strcmp(buf, pt[i].name) == 0)
		{
			flag = 0;
			printf("信息 %s,%d 已删除\n", pt[i].name, pt[i].age);
			continue;//匹配到
		}
		fwrite(pt + i, sizeof(student), 1, p);
		//printf("%s, %d\n", (pt + i)->name, (pt + i)->age);
	}

	if (flag)
	{
		printf("查无此人\n");
	}

	fclose(p);
	printf("stu.txt 已保存\n");
	free(pt);
	return 0;
}

int Clear()
{
	system("cls");//windows清屏命令
	return 0;
}

void menu()
{
	printf("**************************\n");
	printf("* 1 输入信息\n");
	printf("* 2 查询信息\n");
	printf("* 3 删除用户\n");
	printf("* 4 清除屏幕\n");
	printf("* 5 列出名单\n");
	printf("* 6 退出程序\n");
	printf("**************************\n");
}

void modify()
{
	int(*p[])() = {Input, Search, Delete, Clear, List};//函数指针数组
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
			printf("错误，请重新输入：");
	}
}

int main(void)
{
	modify();
	printf("Compelete\n");
	return 0;
}