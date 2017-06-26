#include <iostream>

using namespace std;

#include "模板类_容器训练.h"

template <typename T>
Concrete<T>::Concrete(int len)//构造函数
{
	array = new T[len];
}

template <typename T>
Concrete<T>::Concrete(const Concrete<T> & obj)//拷贝构造
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
Concrete<T> & Concrete<T>::operator=(const Concrete<T> & obj)//等号操作符重载
{
	if (NULL != array)
	{

	}
	return obj;
}

template <typename T>
ostream & operator<<(ostream & out, const Concrete<T> & obj)//<<操作符重载
{
	return out;
}
