#include "choice.h"

void test6()
{
	CDemo ob;
	cout << sizeof(ob) << endl;
}

void test9()
{
	Base b;
	Derived d;

	Base*   pb = new Derived;
	b.f(1.0);
	//d.f(1.0);
	pb->f(1.0);
	delete pb;

	int isize = sizeof(Derived);
}

void test10()
{
	Base   b;
	Derived d;
	Base*   pb = new Derived;
	b.g();
	d.g();
	pb->g();
	delete pb;
}

void test15()
{
	CBaseClass * pCBaseA = new CBaseClass();
	CBaseClass * pCBaseB = new CDerivedClass();
	CDerivedClass * pCDerivedClass = new CDerivedClass();

	int i = pCBaseA->GetResult();
	int j = pCBaseB->GetResult();
	int k = pCDerivedClass->GetResult();

	cout << i << "," << j << "," << k << endl;

	delete pCBaseA;
	delete pCBaseB;
	delete pCDerivedClass;
}

class R
{
public:
	R(){}
	void print(){ cout << "not const print" << endl; }   //    (1)
	void print() const{ cout << "const print" << endl; } //    (2)
};

void test2()
{
	R a;
	a.print();            //调用（1）

	const R b;
	b.print();             //调用（2）
}