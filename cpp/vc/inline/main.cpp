#include <iostream>

int max(int, int, int); //函数声明，左端也可以加inline

int main()
{
	int i = 10, j = 20, k = 30, m;
	m = max(i, j, k);
    std::cout << "max = " << m << std::endl;
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    std::cout << "k = " << k << std::endl;
	return 0;
}

inline int max(int a, int b, int c) //定义max为内联函数
{
	if (b > a) a = b;
	if (c > a) a = c;
	return a;
}
