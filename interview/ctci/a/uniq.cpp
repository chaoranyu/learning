#include <iostream>
//#include <string>
using namespace std;

bool IsUnique1(string s)
{
	bool a[256] = {false};
//	memset(a, 0, sizeof(a));
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		int v = (int)s[i];
		if (a[v]) return false;
		a[v] = true;
	}

	return true;
}

bool IsUnique2(string s)
{
	int a[8] = {0};
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		int v = (int)s[i];
		int idx = v / 32, shift = v % 32;
		if (a[idx] & (1 << shift)) return false;
		a[idx] |= (1 << shift);
	}

	return true;
}

// charactor set is a-z
bool IsUnique3(string s)
{
	int check = 0;
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		int v = (int)(s[i] - 'a');
		if (check & (1 << v)) return false;
		check |= (1 << v);
	}

	return true;
}

int main()
{
	string s1 = "hello, world";
	string s2 = "abcdefghijklmnopqrstuvwxyzABCD1234567890";

	cout << IsUnique1(s1) << ", " << IsUnique2(s1) << endl;
	cout << IsUnique1(s2) << ", " << IsUnique2(s2) << endl;

	return 0;
}
