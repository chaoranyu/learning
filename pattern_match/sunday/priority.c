#include <stdio.h>

void main()
{
	int n = 3;
	n *= 2 + 4;
	printf("%d\n", n);
	printf("%d\n", n *= 2 + 4);
	/* int m = 1; */
	/* n = 2 > 1 ? 10 : m++; */
	/* printf("%d\n", m); */
	/* n = 2 > 1 ? m++ : 100; */
	/* printf("%d\n", m); */
}
