#include <iostream>

using namespace std;

#include "ģ����_����ѵ��.h"

template <typename T>
Concrete<T>::Concrete(int len)//���캯��
{
	array = new T[len];
}

template <typename T>
Concrete<T>::Concrete(const Concrete<T> & obj)//��������
{
	if (this->array != NULL)
	{
		delete[] array;
		array = NULL;
		m_len = 0
	}

	m_len = obj.m_len;
	array = new T[m_len];
}

template <typename T>
Concrete<T>::~Concrete()
{
	delete[] array;
	array = NULL;
}


template <typename T>
Concrete<T> & Concrete<T>::operator=(const Concrete<T> & obj)//�ȺŲ���������
{
	if (NULL != array)
	{

	}
	return obj;
}

template <typename T>
ostream & operator<<(ostream & out, const Concrete<T> & obj)//<<����������
{
	return out;
}
