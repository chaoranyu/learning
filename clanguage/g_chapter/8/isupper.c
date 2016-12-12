#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isupper1(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int isupper2(int c)
{
	return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", c) != NULL);
}

/*
int isupper3(int c)
{
	return ((_Ctype[(unsigned char)c] & _UP) != 0);
}
*/

main()
{
	int i, j;

	for (i = 0; i < 10000000; i++)
		for(j = 0x60; j < 0x7A; j++) {
			isupper1(j);
			isupper2(j);
			/* isupper3(j); */
		}
}
