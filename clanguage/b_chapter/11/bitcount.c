#include <stdio.h>

int bitcount(unsigned x);
int bitcount2(unsigned x);

void main()
{
	unsigned x;
	scanf("%d", &x);
	printf("%d\n", bitcount(x));
	printf("%d\n", bitcount2(x));
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;

	for (b=0; x != 0; x >>= 1)
		if (x & 1)    //if (x & 01)
			b++;
	return b;
}
int bitcount2(unsigned x)
{
	int b;

	for (b=0; x != 0; x &= x-1)
		b++;
	return b;
}
