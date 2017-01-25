#include "choice.h"
#include <list>

void test5()
{
	CChild child;
}

int test6a()
{
	int k = 10;
	const int &ref = k;
	int &x = const_cast<int &>(ref);
	x = 11;

	return k;
}
int test6b()
{
	const int k = 10;
	//int &x = const_cast<int>(k);
	//x = 11;

	return k;
}

void test6()
{
	cout << test6a() << endl;
	cout << test6b() << endl;
}

void foo(std::list<int> * const plist)
{
	plist->sort();
}

void test7()
{
	list<int> list;
	foo(&list);
}