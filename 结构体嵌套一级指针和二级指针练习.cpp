#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结构体嵌套一级指针和二级指针练习
//结构体类型，每个导师有三个学生
typedef struct Teacher
{
	char *tName; //导师名字，需要动态分配空间
	char **stu;  //三个学生，需要动态分配空间，堆区数组
	int age;
}Teacher;

//释放空间，在函数内部把p赋值为NULL
void freeTeacher(Teacher **p, int n1, int n2)
{
	if (p == NULL || *p == NULL)
		fprintf(stderr, "func freeTeacher NULL pointer\n");

	Teacher *temp = *p;
	for (int i = 0; i < n1; i++)//释放老师姓名 学生信息空间
	{
		if (temp[i].tName != NULL)//释放老师姓名空间
		{
			free(temp[i].tName);
			temp[i].tName = NULL;
		}
		char ** stu_t = temp[i].stu;//每个学生的姓名空间
		for (int j = 0; j < n2; j++)//释放学生信息需要先释放学生姓名
		{
			if (stu_t[j] != NULL)//释放掉
			{
				free(stu_t[j]);
				stu_t[j] = NULL;
			}
		}

		if (stu_t != NULL)//释放3个学生的空间
		{
			free(stu_t);
			temp[i].stu = NULL;
		}
	}

	if (temp != NULL)//释放结构体空间
	{
		free(temp);
		*p = NULL;
	}
}

//在createTeacher中分配空间
int createTeacher(Teacher **p/*out*/, int n1, int n2)
{
	int res = 0;
	if (p == NULL)	//空指针处理
	{
		res = -1;
		fprintf(stderr, "func createTeacher NULL pointer\n");
		return res;
	}

	Teacher * temp = (Teacher*)calloc(n1, sizeof(Teacher));//老师数组分配空间
	if (temp == NULL)	
	{
		res = -2;
		fprintf(stderr, "main dimention allocate failed\n");
		return res;
	}

	//每个老师 名下的分配一组 学生名字数组 和 老师名字
	for (int i = 0; i < n1; i++)
	{
		temp[i].tName = (char*)calloc(100, sizeof(char));//每个老师的名字
		if (temp[i].tName == NULL)
		{
			res = -3;
			fprintf(stderr, "teacher's name allocate failed\n");
			freeTeacher(&temp, n1, n2);
			return res;
		}

		char **stu_t = (char**)calloc(n2, sizeof(char*));//每个老师带的3个学生
		if (stu_t == NULL)
		{
			res = -4;
			fprintf(stderr, "student allocate failed\n");
			freeTeacher(&temp, n1, n2);
			return res;
		}

		for (int j = 0; j < n2; j++)
		{
			stu_t[j] = (char*)calloc(100, sizeof(char));//每个学生的名字
			if (stu_t[j] == NULL)
			{
				res = -5;
				fprintf(stderr, "student's name allocate failed\n");
				freeTeacher(&temp, n1, n2);
				return res;
			}
		}

		temp[i].stu = stu_t;	//临时指针分配好空间后把地址赋值给结构体成员指针
	}

	*p = temp;	//临时结构体变量分配好全部内存后把堆地址赋值给实参
	printf("allocate success\n");
	return res;
}

//给成员赋值
void initTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL)
		fprintf(stderr, "func initTeacher NULL pointer\n");

	for (int i = 0; i < n1; i++)
	{
		sprintf(p[i].tName, "teacher%d", i + 1);//老师名字
		p[i].age = 30 + 2 * i;	//老师年龄

		for (int j = 0; j < n2; j++)//每个老师带的学生们
		{
			//char **stu_t = p[i].stu;
			sprintf(p[i].stu[j], "stu%d%d%d", j, j, j);//每个学生的名字
		}
	}
}

//打印结构体成员信息
void printTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL)
		fprintf(stderr, "func printTeacher NULL pointer\n");

	for (int i = 0; i < n1; i++)
	{
		printf("老师的名字：%s，年龄：%d，带的学生有：\n", p[i].tName, p[i].age);
		for (int j = 0; j < n2; j++)
		{
			printf("%s\n", (p[i].stu)[j]);
		}
		printf("-----------------------\n");
	}
}


//根据导师名字排序, 降序
void sortTeacher(Teacher *p, int n)
{
	int res = 0;
	if (p == NULL)
		fprintf(stderr, "func sortTeacher NULL pointer\n");

	Teacher * temp = p;//辅助指针
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(temp[i].tName, temp[j].tName) < 0)
			{
				Teacher swap = temp[i];
				temp[i] = temp[j];
				temp[j] = swap;
			}
		}
	}
}



int main(void)
{
	int ret = 0;
	int n1 = 3; //导师个数
	int n2 = 3; //学生
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //给成员赋值

	printf("排序前：\n");//打印成员，排序前
	printTeacher(p, n1, n2);

	//根据导师名字排序, 降序
	sortTeacher(p, n1);

	//打印成员，排序后
	printf("\n排序后：\n");
	printTeacher(p, n1, n2);

	//释放空间，在函数内部把p赋值为NULL
	freeTeacher(&p, n1, n2);

	return 0;
}