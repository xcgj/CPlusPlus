#include "iostream"
using namespace std;
#include "cir_and_point.h"
int main(void)
{
	cir o;
	point d;
	
	cout << "��� x, y ����" << endl;
	cin >> d.point_x;
	cin >> d.point_y;

	double m, n, h;
	cout << "Բ�� x, y ����Ͱ뾶" << endl;
	cin >> m;
	cin >> n;
	cin >> h;
	o.GetPXYR(m, n, h);

	double ret = o.C_P_comp(d);
	if (ret == 0)
		cout << "��Բ��" << endl;
	else if (ret > 0)
		cout << "��Բ��" << endl;
	else
		cout << "��Բ��" << endl;

	return 0;
}
//���
//����Բ���࣬Բ������ �뾶
//����� ����
//��������ȥԲ������ ��뾶
//��Բ���ߵ������ʵ�� �жϺ���