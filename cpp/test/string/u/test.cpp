#include <iostream>
using namespace std;

#include "test.h"

int main() {
	char * s1 = "abc", s2;

	cout << s1 + 1 << endl;
	cout << sizeof(s1) << " " << sizeof(s2) << endl;

	int * m, n;

	cout << sizeof(m) << " " << sizeof(n) << endl;
	cout << sizeof(void *) << endl;


	Stack test("hello");

	const char *ss = test.getString();
	cout << ss << endl;

	ss = s1;
	cout << ss << endl;

	// *ss = 'a';

	return 0;
}
