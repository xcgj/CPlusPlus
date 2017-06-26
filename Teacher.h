#pragma once
/* 只包含一次
 * 作用等同于：
 * #ifndef __AH__
 * #define __AH__
 * ……
 * #endif
 */
class Teacher
{
public:
	Teacher();
	~Teacher();
	int& MaxCom(int &, const int &);
};

