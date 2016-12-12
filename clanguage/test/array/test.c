#include <stdlib.h>
#include <stdio.h>

void main()
{
	char a[3][4] = {"aaa", "bb", "ccc"};
	char (*q)[4] = a;
	int i;
	*(*q+3) = 'b';

	for (i = 0; i<3; i++)
	{
		printf("%s", q[i]);
	}
}

