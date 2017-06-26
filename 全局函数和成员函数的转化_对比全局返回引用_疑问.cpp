#include "iostream"
using std::cin;
using std::cout;
using std::endl;

class A
{
public:
	int a;
	A(int m = 0)
	{
		a = m;
		cout << "构造" << a << endl;
	}
	A(const A &abc)
	{
		this->a = abc.a;
		cout << "赋值构造" << a << endl;
	}
	A calc(A &ano)	//成员函数，隐藏了A * const this： void calc(A * const this, A ano)
	{				//问题：若改成A& calc(A &ano)，此时会产生匿名对象吗？？？？？？？？？？？？？编译时黑窗口不显示
		A temp(this->a + ano.a);
		cout << "calc" << temp.a << endl;
		return temp;	//析构temp，返回匿名对象
	}
	~A()
	{
		cout << "析构" << a << endl;
	}
};

A& Gcalc(A *a1, A &a2)	//全局函数,返回匿名对象	//返回引用，a3会先析构，再生成匿名对象！！！
{
	A a3(33);
	a3.a = a1->a + a2.a;
	cout << "全局函数调用结束" << endl;
	return a3;
}



int main(void)
{
	A m(1), n(2);
	A t;
	t = m.calc(n);	//成员函数，匿名对象把值复制给t，匿名对象析构
	A g = Gcalc(&m, n);	//全局函数	//匿名对象的属性是乱码
	cout << "主函数调用结束" << endl;
	return 0;
}
/*
构造1	//m
构造2	//n
构造0	//t
构造3	//temp
calc3
赋值构造3	//成员函数 匿名对象
析构3	//temp
析构3	//成员函数 匿名对象
构造33	//a3
全局函数调用结束
析构3	//a3先析构
赋值构造？	//全局函数 匿名对象	//乱码
主函数调用结束
析构？	//全局函数 匿名对象->g	//乱码
析构3
析构2
析构1
*/