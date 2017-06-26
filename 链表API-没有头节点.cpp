#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int id;				//������
	struct Node *next;	//ָ����
}SLIST;

void SListDestroy(SLIST * p)		//�ͷ����нڵ�
{
	SLIST * temp = NULL;
	while (p)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
}

//ɾ��ֵΪx�����н��
SLIST * SListNodeDelPro(SLIST *pHead, int x)
{
	int res = 0;
	if (pHead == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return pHead;
	}

	int flag = 0;
	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	if (pHead->id == x)	//����ͷ�ڵ�ɾ�������
	{
		pHead->next = NULL;
		free(pHead);
		pHead = pCur;
	}

	while (pCur)
	{
		if (pCur->id == x)
		{
			pCur = pCur->next;
			SLIST *temp = pPre->next;
			temp->next = NULL;
			free(temp);

			pPre->next = pCur;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	return pHead;
}

//����ڵ����򣬽�������������
int SListNodeSort(SLIST *pHead)
{
	int res = 0;
	if (pHead == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}
	
	int index = 1;	//Ԫ�ظ���
	SLIST *pCur = pHead->next;
	while (pCur)
	{
		pCur = pCur->next;
		index++;
	}

	SLIST *pPre = pHead;
	SLIST * loop = pPre;

	for (int i = 0; i < index - 1; i++)
	{
		pPre = loop;		//�����ѭ����ʼλ��
		pCur = pPre->next;	//�����ѭ����ʼλ��
		for (int j = i + 1; j < index; j++)
		{
			if (pPre->id > pCur->id)
			{
				SLIST temp = *pPre;
				//temp.id = pPre->id;
				pPre->id = pCur->id;	//ֻ����������
				pCur->id = temp.id;
			}
			pCur = pCur->next;//��ѭ��������
		}
		loop = loop->next;	//ÿ����ѭ����һ��
	}
/*	//ע�⣬����nextָ�뻹��Ҫ����
	if (pPre->id > pCur->id) //����
	{
		//�Ƚ����ڵ�����
		SLIST tmp = *pCur;
		*pCur = *pPre;
		*pPre = tmp;

		//�����½���һ��nextָ��������ָ��ָ�
		tmp.next = pCur->next;
		pCur->next = pPre->next;
		pPre->next = tmp.next;
	}*/
	return 0;
}

//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
int SListNodeInsertPro(SLIST *pHead, int x)//	x��id��ֵ
{
	int res = 0;
	if (pHead == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}

	SLIST * pPre = pHead;
	SLIST * pCur = pPre->next;

	while (pCur)//pPre��NULLҲ����ѭ��
	{
		if (x <= pCur->id && x >= pPre->id)
		{
			break;	//�ҵ��˾�����ѭ��
		}

		pPre = pCur;
		pCur = pCur->next;
	}

	SLIST *temp = (SLIST*)calloc(1, sizeof(SLIST));
	if (temp == NULL)
	{
		printf("err, allacate failed\n");
		res = -2;
		return res;
	}
	temp->id = x;

	temp->next = pPre->next;
	pPre->next = temp;

	return 0;
}

//��ת����Ľڵ㣨���������Ƿ�ת������������ָ����
//���磺ԭ����ΪA->B->C->D,ʹ�������ó�ΪD->C->B->A
int SListNodeReverse(SLIST **pHead)//ͷ�ڵ�����
{
	int res = 0;
	if (pHead == NULL || *pHead == NULL || (*pHead)->next == NULL)//ֻ��һ���ڵ���������
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}

	SLIST *pPre = *pHead;
	SLIST *pCur = pPre->next;
	SLIST *temp = NULL;

	while (pCur)
	{
		temp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = temp;
	}

	//����ͷβ�ڵ�
	temp = (*pHead)->next;//�ڶ����ڵ�
	temp->next = *pHead;
	(*pHead)->next = NULL;
	*pHead = pPre;
	return 0;
}

int SListNodeReverse2(SLIST *pHead)//ͷ�ڵ㲻����
{
	int res = 0;
	if (pHead == NULL || pHead->next == NULL)//ֻ��һ���ڵ���������
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}
	
	SLIST *pPre = pHead;
	SLIST *pCur = pPre->next;
	SLIST *temp = NULL;

	while (pCur)
	{
		temp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = temp;
	}

	//����ͷβ�ڵ�
	temp = pHead->next;	//�ڶ����ڵ�
	pHead->next = pPre;
	temp->next = NULL;
	return 0;
}

void SListPrint(SLIST * p)//�������нڵ�
{
	for (int i = 0; p; i++)
	{
		printf("��%d���ڵ��ֵΪ��%d\n", i, p->id);
		p = p->next;
	}
}

SLIST * SListCreat()//�����ڵ�
{
	SLIST *temp = (SLIST*)calloc(1, sizeof(SLIST));
	if (temp == NULL)
	{
		printf("err, allocate failed\n");
		exit(0);
	}
	temp->id = 1;
	temp->next = NULL;
	SLIST *t = temp;//����ͷ�ڵ�

	for (int i = 0; i < 5; i++)
	{
		SLIST *tp = (SLIST*)calloc(1, sizeof(SLIST));
		temp->next = tp;	//�����ڵ�����
		temp = temp->next;	//�����¸��ڵ�
		if (NULL == temp)
		{
			printf("err, allocate failed\n");
			SListDestroy(t);
		}
		temp->id = 2 * i;
	}
	temp->next = NULL;		//β�ڵ�

	return t;
}

int main01()
{
	SLIST *pHead = NULL;

	pHead = SListCreat(); //����ͷ���
	printf("\n����ͷ����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeDelPro(pHead, 4);//ɾ������ֵΪ4�Ľ��
	printf("\nɾ������ֵΪ4�Ľ��\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeSort(pHead);//����ڵ�����
	printf("\n����ڵ�����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeInsertPro(pHead, 5);//�������5
	printf("\n�������5��\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeReverse2(pHead); //��ת����Ľڵ㣨���������Ƿ�ת��
	printf("\n��ת����Ľڵ�\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeReverse(&pHead); //��ת����Ľڵ㣨����ͷ�ڵ㣩
	printf("\n��ת����Ľڵ�\n");
	SListPrint(pHead); //�������нڵ�

	SListDestroy(pHead);//�ͷ����нڵ�
	pHead = NULL;

	return 0;
}