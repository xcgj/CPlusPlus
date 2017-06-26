#pragma once

#include <iostream>



template <typename T>
class Concrete
{
	friend ostream & operator<< <T> (ostream & out, const Concrete & obj);//<<����������

public:
	Concrete(int len = 0);//���캯��

	Concrete(const Concrete & obj);//��������

	~Concrete();

	int GetLen()
	{
		return m_len;
	}

	Concrete & operator= (const Concrete & obj);//�ȺŲ���������



private:
	T * array;
	int m_len;
};