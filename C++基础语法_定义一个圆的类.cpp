#include "iostream"	//����c++��ͷ�ļ�
using namespace std;	//ʹ��std��׼�������ռ䣬������������ռ��ж����˺ܶ��׼���壩

class Circle
//������һ���࣬�Ǹ��������ͣ��̶��ڴ��С�ı��������ڴ���û�з���ռ䣬
//ֻ�����ඨ���˶��󣬲����ڴ�ռ�
{
public:
	double a;//�뾶�����ԣ���Ա����
	double b;//�ܳ������ԣ���Ա����
	double c;//��������ԣ���Ա����
	double getR(double r)//�Ӷ����ò�������Ա����
	{
		return a = r;
	}
	double getGirth()//��Ա����
	{
		return b = 3.14 * 2 * a;
	}
	double getArea()//��Ա����
	{
		return c = 3.14 * a * a;
	}
};

void main1()
{
	Circle a1, a2;//����������������󣨱�����
	cout << "�� Circle �Ĵ�С��" << sizeof(a1) << endl;
	//endl  ���У���ˢ�»�����
	cout << "sizeof(double)��" << sizeof(double) << endl;
	double i = 0;
	cout << "������뾶��";
	cin >> i;
	cout << "Բ�İ뾶��" << a1.getR(i) << endl;
	cout << "Բ���ܳ���" << a1.getGirth() << endl;
	cout << "Բ�������" << a1.getArea() << endl << endl << endl;;

	cout << "������뾶��";
	cin >> i;
	a2.getR(i);//��������Ը�ֵ
	cout << "Բ���ܳ���" << a2.getGirth() << endl;
	cout << "Բ�������" << a2.getArea() << endl;
}