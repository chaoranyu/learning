#include <iostream>
#include "mystring.h"
using namespace std;

template <class T>
void myswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	MyString str1("hello"), str2("world!!!!");
	float f = 3.4, g = 5.6;
	myswap(str1, str2);
	myswap(f, g);
	cout << str1 << endl;
	cout << str2 << endl;
	cout << f << endl;
	cout << g << endl;

	return 0;
}
