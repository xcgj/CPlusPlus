a) һ�����ͣ�An integer��
int p;
b) һ��ָ�����͵�ָ�루A pointer to an integer��
int * p;
c) һ��ָ�� ָ�����͵�ָ�루A pointer to a pointer to an integer��
int ** p;
d) һ�����10�����͵����飨An array of 10 integers��
int p[10];
e) һ�����10��ָ������ָ������飨An array of 10 pointers to integers��
int * p[10];
f) һ��ָ����10�����������ָ�루A pointer to an array of 10 integers��
int(*p)[10];
g) һ��ָ�� ��Ҫһ�����Ͳ������ҷ���ֵ��һ�����͵ĺ���ָ��
��A pointer to a function that takes an integer as an argument and returns an integer��
int (*p)(int)
h) һ�����10�� ָ�� ��Ҫһ�����Ͳ������ҷ���ֵ��һ�����ͺ�����ָ�������
��An array of ten pointers to functions that take an integer argument and return an integer��
int (*p[10])(int)