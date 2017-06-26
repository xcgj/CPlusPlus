

#include<vector>
#include<string>
#include<iostream>
using namespace std;
class BigBase {
public:
	BigBase() { mParam = 0; }
	void func() { cout << "BigBase::func" << endl; }
public:
	int mParam;
};

#if 0

class Base1 :  public BigBase {};
class Base2 :  public BigBase {};

#endif // 0

class Base1 : virtual public BigBase {};
class Base2 : virtual public BigBase {};
class Derived : public Base1, public Base2 {};

int main() {

	Derived derived;
	//1. 对“func”的访问不明确
	//derived.func();
	//cout << derived.mParam << endl;
	cout << "derived.Base1::mParam:" << derived.Base1::mParam << endl;
	cout << "derived.Base2::mParam:" << derived.Base2::mParam << endl;

	//2. 重复继承
	cout << "Derived size:" << sizeof(Derived) << endl; //8

	return EXIT_SUCCESS;
}

/*
没有虚基类继承时：
class Derived   size(8):
+---
0      | +--- (base class Base1)
0      | | +--- (base class BigBase)
0      | | | mParam
| | +---
| +---
4      | +--- (base class Base2)
4      | | +--- (base class BigBase)
4      | | | mParam
| | +---
| +---
+---
*/

/*
虚基类继承时：
class Derived   size(12):
+---
0      | +--- (base class Base1)
0      | | {vbptr}
| +---
4      | +--- (base class Base2)
4      | | {vbptr}
| +---
+---
+--- (virtual base BigBase)
8      | mParam
+---

Derived::$vbtable@Base1@:
0      | 0
1      | 8 (Derivedd(Base1+0)BigBase)

Derived::$vbtable@Base2@:
0      | 0
1      | 4 (Derivedd(Base2+0)BigBase)
vbi:       class  offset o.vbptr  o.vbte fVtorDisp
		 BigBase       8       0       4 0
*/