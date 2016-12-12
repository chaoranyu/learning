#include <stdio.h>

void func(char *s, char *t, char *u)
{
	int ascii[256] = {0};
	char c;

	while (c = *s++) {
		ascii[c]++;
	}

	while (c = *t++) {
		if (ascii[c]++ == 0) {
			*u++ = c;
		}
	}
}


int main()
{
	char s[100];
	char t[100];
	char u[100];

	scanf("%s", s);
	scanf("%s", t);

	func(s, t, u);

	printf("%s\n", u);

	return 0;
}
