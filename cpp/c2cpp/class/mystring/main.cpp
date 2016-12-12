#include <iostream>
#include "mystring.h"
using namespace std;

int main(void)
{
	MyString str("hello");
	MyString str1 = str;
	cout << "Length of str1: " << str1.Length() << endl;
	cout << "Value of str1: " << str1 << endl;

	MyString str2 = "";
	cout << "Is str2 empty? " << (str2.IsEmpty()? "true" : "false") << endl;

	str2 = "world";
	cout << "New value of str2: " << str2 << endl;

	cout << "New value of str: " << str1 + str2 << endl;
	cout << "Value of another expression: " << str1 + ", world" << endl;
	cout << "Value of yet another expression: " << "hello, " + str2 << endl;

	MyString str3 = str1 + str2;
	cout << "Value of str3: " << str3 << endl;

	return 0;
}
