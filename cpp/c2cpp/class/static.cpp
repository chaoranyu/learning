#include <iostream>
using namespace std;

class A
{
public:
	static int i;
	int j;
	static void foo() {cout << i << endl;} // can't print j
};

int A::i; // 定义变量

int main(void)
{
	A a, b;
	a.i = 10;
	b.i = 20;
	a.foo();
	b.foo();
	A::foo();
	cout << a.i << endl << b.i << endl;
	A::i = 30;
	cout << a.i << endl << b.i << endl;
	cout << sizeof(a) << ", " << sizeof(b) << endl;

	return 0;
}
