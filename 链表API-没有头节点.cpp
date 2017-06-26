#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int id;				//数据域
	struct Node *next;	//指针域
}SLIST;

void SListDestroy(SLIST * p)		//释放所有节点
{
	SLIST * temp = NULL;
	while (p)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
}

//删除值为x的所有结点
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
	if (pHead->id == x)	//处理头节点删除的情况
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

//链表节点排序，交换的是数据域
int SListNodeSort(SLIST *pHead)
{
	int res = 0;
	if (pHead == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}
	
	int index = 1;	//元素个数
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
		pPre = loop;		//获得外循环起始位置
		pCur = pPre->next;	//获得外循环起始位置
		for (int j = i + 1; j < index; j++)
		{
			if (pPre->id > pCur->id)
			{
				SLIST temp = *pPre;
				//temp.id = pPre->id;
				pPre->id = pCur->id;	//只交换数据域
				pCur->id = temp.id;
			}
			pCur = pCur->next;//内循环往下走
		}
		loop = loop->next;	//每次外循环走一步
	}
/*	//注意，排序，next指针还需要交换
	if (pPre->id > pCur->id) //升序
	{
		//先交换节点整体
		SLIST tmp = *pCur;
		*pCur = *pPre;
		*pPre = tmp;

		//再重新交换一下next指针域将链表指向恢复
		tmp.next = pCur->next;
		pCur->next = pPre->next;
		pPre->next = tmp.next;
	}*/
	return 0;
}

//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(SLIST *pHead, int x)//	x是id的值
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

	while (pCur)//pPre是NULL也结束循环
	{
		if (x <= pCur->id && x >= pPre->id)
		{
			break;	//找到了就跳出循环
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

//翻转链表的节点（不是排序，是翻转），交换的是指针域
//例如：原链表为A->B->C->D,使链表逆置成为D->C->B->A
int SListNodeReverse(SLIST **pHead)//头节点逆置
{
	int res = 0;
	if (pHead == NULL || *pHead == NULL || (*pHead)->next == NULL)//只有一个节点无需逆置
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

	//处理头尾节点
	temp = (*pHead)->next;//第二个节点
	temp->next = *pHead;
	(*pHead)->next = NULL;
	*pHead = pPre;
	return 0;
}

int SListNodeReverse2(SLIST *pHead)//头节点不逆置
{
	int res = 0;
	if (pHead == NULL || pHead->next == NULL)//只有一个节点无需逆置
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

	//处理头尾节点
	temp = pHead->next;	//第二个节点
	pHead->next = pPre;
	temp->next = NULL;
	return 0;
}

void SListPrint(SLIST * p)//遍历所有节点
{
	for (int i = 0; p; i++)
	{
		printf("第%d个节点的值为：%d\n", i, p->id);
		p = p->next;
	}
}

SLIST * SListCreat()//创建节点
{
	SLIST *temp = (SLIST*)calloc(1, sizeof(SLIST));
	if (temp == NULL)
	{
		printf("err, allocate failed\n");
		exit(0);
	}
	temp->id = 1;
	temp->next = NULL;
	SLIST *t = temp;//保存头节点

	for (int i = 0; i < 5; i++)
	{
		SLIST *tp = (SLIST*)calloc(1, sizeof(SLIST));
		temp->next = tp;	//建立节点连接
		temp = temp->next;	//跳到下个节点
		if (NULL == temp)
		{
			printf("err, allocate failed\n");
			SListDestroy(t);
		}
		temp->id = 2 * i;
	}
	temp->next = NULL;		//尾节点

	return t;
}

int main01()
{
	SLIST *pHead = NULL;

	pHead = SListCreat(); //创建头结点
	printf("\n创建头结点后\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeDelPro(pHead, 4);//删除所有值为4的结点
	printf("\n删除所有值为4的结点\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeSort(pHead);//链表节点排序
	printf("\n链表节点排序\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeInsertPro(pHead, 5);//升序插入5
	printf("\n升序插入5后\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeReverse2(pHead); //翻转链表的节点（不是排序，是翻转）
	printf("\n翻转链表的节点\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeReverse(&pHead); //翻转链表的节点（包括头节点）
	printf("\n翻转链表的节点\n");
	SListPrint(pHead); //遍历所有节点

	SListDestroy(pHead);//释放所有节点
	pHead = NULL;

	return 0;
}