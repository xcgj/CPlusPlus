#pragma once

#include <iostream>



template <typename T>
class Concrete
{
	friend ostream & operator<< <T> (ostream & out, const Concrete & obj);//<<操作符重载

public:
	Concrete(int len = 0);//构造函数

	Concrete(const Concrete & obj);//拷贝构造

	~Concrete();

	int GetLen()
	{
		return m_len;
	}

	Concrete & operator= (const Concrete & obj);//等号操作符重载



private:
	T * array;
	int m_len;
};