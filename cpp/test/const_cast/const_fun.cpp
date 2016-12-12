#include <iostream>
using namespace std;

class A
{
public:
	void p() { cout << "p()" << endl; }
	void p() const { cout << "p() const" << endl; }
};

int main()
{
	A a1;
	a1.p();

	const A a2;
	a2.p();

	return 0;
}
