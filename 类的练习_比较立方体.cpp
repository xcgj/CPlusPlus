#include "iostream"
using namespace std;
#include "circl.h"

int main(void)
{
	circl a, b;
	int x = 0, y = 0;
	int &m = x, &n = y;
	cout << "�����������ⳤ��" << endl;
	cin >> m;
	cin >> n;
	a.SetArris(x);
	b.SetArris(y);
	bool ret = a.CompareArris(b);
	if (ret)
		cout << "���" << endl;
	else
		cout << "�����" << endl;
	return 0;
}