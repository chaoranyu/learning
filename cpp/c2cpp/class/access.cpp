#include <iostream>
using namespace std;

class A
{
public:
	int pub;
protected:
	int prot;
private:
	int priv;
};

class B: protected A
{
public:
	void foo(void) { cout << pub << prot << endl; }
	/* void foo(void) { cout << pub << prot << priv << endl; } */
};

int main(void)
{
	B b;
	/* cout << b.pub << endl; */
	
	return 0;
}
