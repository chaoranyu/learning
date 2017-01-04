#include <iostream>

class A
{
public:
	A(int i = 16) : n(i) { std::cout << "A::construct, n = " << n << "\n"; }

private:
	int n;
};

class B
{
public:
	B(int i = 16) { n = i; std::cout << "B::construct, n = " << n << "\n"; }

private:
	int n;
};

int main(int argc, char *argv[])
{
	A a;
	B b;

	return 0;
}
