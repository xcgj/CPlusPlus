#include "iostream"
using namespace std;
#include "circl.h"

int main(void)
{
	circl a, b;
	int x = 0, y = 0;
	int &m = x, &n = y;
	cout << "两个立方体棱长：" << endl;
	cin >> m;
	cin >> n;
	a.SetArris(x);
	b.SetArris(y);
	bool ret = a.CompareArris(b);
	if (ret)
		cout << "相等" << endl;
	else
		cout << "不相等" << endl;
	return 0;
}