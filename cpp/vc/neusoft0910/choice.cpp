#include "stdafx.h"

//#include "choice.h"

//#include <iostream>
//using namespace std;

void test11()
{
	ClassA testA; // just for test
	ClassB b;
	ClassA & a = b;

	a.foo(5.0);
	b.foo(5.0);
}

int CA::ms_iCounter = 0;

void test13()
{
	CA a[2];
	CA b = a[1];	// copy construct
	CA c;
	c = a[1];

	cout << CA::ms_iCounter << endl;
}

void test15(void)
{
	Derived d;
	Base *pb = &d;

	pb->h(3.14f);
}

void test30()
{
	int *a = new int[10];
	for (int i = 0; i < 10; i++)
	{
		*(a + i) = i;
	}

	delete[]a;
}


