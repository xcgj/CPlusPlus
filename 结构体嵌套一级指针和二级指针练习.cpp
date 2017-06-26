#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ṹ��Ƕ��һ��ָ��Ͷ���ָ����ϰ
//�ṹ�����ͣ�ÿ����ʦ������ѧ��
typedef struct Teacher
{
	char *tName; //��ʦ���֣���Ҫ��̬����ռ�
	char **stu;  //����ѧ������Ҫ��̬����ռ䣬��������
	int age;
}Teacher;

//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
void freeTeacher(Teacher **p, int n1, int n2)
{
	if (p == NULL || *p == NULL)
		fprintf(stderr, "func freeTeacher NULL pointer\n");

	Teacher *temp = *p;
	for (int i = 0; i < n1; i++)//�ͷ���ʦ���� ѧ����Ϣ�ռ�
	{
		if (temp[i].tName != NULL)//�ͷ���ʦ�����ռ�
		{
			free(temp[i].tName);
			temp[i].tName = NULL;
		}
		char ** stu_t = temp[i].stu;//ÿ��ѧ���������ռ�
		for (int j = 0; j < n2; j++)//�ͷ�ѧ����Ϣ��Ҫ���ͷ�ѧ������
		{
			if (stu_t[j] != NULL)//�ͷŵ�
			{
				free(stu_t[j]);
				stu_t[j] = NULL;
			}
		}

		if (stu_t != NULL)//�ͷ�3��ѧ���Ŀռ�
		{
			free(stu_t);
			temp[i].stu = NULL;
		}
	}

	if (temp != NULL)//�ͷŽṹ��ռ�
	{
		free(temp);
		*p = NULL;
	}
}

//��createTeacher�з���ռ�
int createTeacher(Teacher **p/*out*/, int n1, int n2)
{
	int res = 0;
	if (p == NULL)	//��ָ�봦��
	{
		res = -1;
		fprintf(stderr, "func createTeacher NULL pointer\n");
		return res;
	}

	Teacher * temp = (Teacher*)calloc(n1, sizeof(Teacher));//��ʦ�������ռ�
	if (temp == NULL)	
	{
		res = -2;
		fprintf(stderr, "main dimention allocate failed\n");
		return res;
	}

	//ÿ����ʦ ���µķ���һ�� ѧ���������� �� ��ʦ����
	for (int i = 0; i < n1; i++)
	{
		temp[i].tName = (char*)calloc(100, sizeof(char));//ÿ����ʦ������
		if (temp[i].tName == NULL)
		{
			res = -3;
			fprintf(stderr, "teacher's name allocate failed\n");
			freeTeacher(&temp, n1, n2);
			return res;
		}

		char **stu_t = (char**)calloc(n2, sizeof(char*));//ÿ����ʦ����3��ѧ��
		if (stu_t == NULL)
		{
			res = -4;
			fprintf(stderr, "student allocate failed\n");
			freeTeacher(&temp, n1, n2);
			return res;
		}

		for (int j = 0; j < n2; j++)
		{
			stu_t[j] = (char*)calloc(100, sizeof(char));//ÿ��ѧ��������
			if (stu_t[j] == NULL)
			{
				res = -5;
				fprintf(stderr, "student's name allocate failed\n");
				freeTeacher(&temp, n1, n2);
				return res;
			}
		}

		temp[i].stu = stu_t;	//��ʱָ�����ÿռ��ѵ�ַ��ֵ���ṹ���Աָ��
	}

	*p = temp;	//��ʱ�ṹ����������ȫ���ڴ��Ѷѵ�ַ��ֵ��ʵ��
	printf("allocate success\n");
	return res;
}

//����Ա��ֵ
void initTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL)
		fprintf(stderr, "func initTeacher NULL pointer\n");

	for (int i = 0; i < n1; i++)
	{
		sprintf(p[i].tName, "teacher%d", i + 1);//��ʦ����
		p[i].age = 30 + 2 * i;	//��ʦ����

		for (int j = 0; j < n2; j++)//ÿ����ʦ����ѧ����
		{
			//char **stu_t = p[i].stu;
			sprintf(p[i].stu[j], "stu%d%d%d", j, j, j);//ÿ��ѧ��������
		}
	}
}

//��ӡ�ṹ���Ա��Ϣ
void printTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL)
		fprintf(stderr, "func printTeacher NULL pointer\n");

	for (int i = 0; i < n1; i++)
	{
		printf("��ʦ�����֣�%s�����䣺%d������ѧ���У�\n", p[i].tName, p[i].age);
		for (int j = 0; j < n2; j++)
		{
			printf("%s\n", (p[i].stu)[j]);
		}
		printf("-----------------------\n");
	}
}


//���ݵ�ʦ��������, ����
void sortTeacher(Teacher *p, int n)
{
	int res = 0;
	if (p == NULL)
		fprintf(stderr, "func sortTeacher NULL pointer\n");

	Teacher * temp = p;//����ָ��
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
	int n1 = 3; //��ʦ����
	int n2 = 3; //ѧ��
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //����Ա��ֵ

	printf("����ǰ��\n");//��ӡ��Ա������ǰ
	printTeacher(p, n1, n2);

	//���ݵ�ʦ��������, ����
	sortTeacher(p, n1);

	//��ӡ��Ա�������
	printf("\n�����\n");
	printTeacher(p, n1, n2);

	//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
	freeTeacher(&p, n1, n2);

	return 0;
}