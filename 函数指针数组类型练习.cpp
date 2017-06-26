a) 一个整型（An integer）
int p;
b) 一个指向整型的指针（A pointer to an integer）
int * p;
c) 一个指向 指向整型的指针（A pointer to a pointer to an integer）
int ** p;
d) 一个存放10个整型的数组（An array of 10 integers）
int p[10];
e) 一个存放10个指向整型指针的数组（An array of 10 pointers to integers）
int * p[10];
f) 一个指向存放10个整型数组的指针（A pointer to an array of 10 integers）
int(*p)[10];
g) 一个指向 需要一个整型参数并且返回值是一个整型的函数指针
（A pointer to a function that takes an integer as an argument and returns an integer）
int (*p)(int)
h) 一个存放10个 指向 需要一个整型参数并且返回值是一个整型函数的指针的数组
（An array of ten pointers to functions that take an integer argument and return an integer）
int (*p[10])(int)