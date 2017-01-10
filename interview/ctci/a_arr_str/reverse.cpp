#include <iostream>
#include <cstring>
using namespace std;

void reverse1(char *str)
{
	if (!str) return;

	char *end = str;
	char tmp;

	while (*end) end++;
	end--;

	while (str < end) {
		char temp = *str;
		*str++ = *end;
		*end-- = temp;
	}
}

void swap(char &a, char &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void reverse2(char *s)
{
	if (!s) return;

	int n = strlen(s);
	for (int i = 0; i < n / 2; i++) {
		swap(s[i], s[n-i-1]);
	}
}

int main()
{
	//char s[] = "abcdefg";
	char *s = NULL;
	reverse1(s);
	cout << s << endl;
	reverse2(s);
	cout << s << endl;

	return 0;
}
