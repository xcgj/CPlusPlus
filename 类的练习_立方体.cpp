#include "iostream"
using namespace std;
#include "cube.h"

int main(void)
{
	int arris = 0;
	cube x;
	cout << "�ⳤ";
	cin >> arris;
	x.GetRidge(arris);
	cout << "���" << x.Proportion() << endl;
	cout << "���" << x.Cubature() << endl;
	return 0;
}
//���
//�������������
//�������н����������ⳤ�ĺ���
//�������� ���� �� ʵ�� ��� �� ��� �ĺ���