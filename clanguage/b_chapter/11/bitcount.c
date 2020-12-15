#include <stdio.h>

int bitcount(unsigned x);
int bitcount2(unsigned x);
int bitcount3(unsigned x);

void main()
{
	unsigned x;
	scanf("%d", &x);
	printf("%d\n", bitcount(x));
	printf("%d\n", bitcount2(x));
	printf("%d\n", bitcount3(x));
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
int bitcount3(unsigned int v)
{
	// See http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel
    unsigned int c; // store the total here

    c = v - ((v >> 1) & 0x55555555);
    c = ((c >> 2) & 0x33333333) + (c & 0x33333333);
    c = ((c >> 4) + c) & 0x0F0F0F0F;
    c = ((c >> 8) + c) & 0x00FF00FF;
    c = ((c >> 16) + c) & 0x0000FFFF;

    // Admittedly it's a bit optimized which makes it harder to read. It's easier to read as:
    // c = (v & 0x55555555) + ((v >> 1) & 0x55555555);
    // c = (c & 0x33333333) + ((c >> 2) & 0x33333333);
    // c = (c & 0x0F0F0F0F) + ((c >> 4) & 0x0F0F0F0F);
    // c = (c & 0x00FF00FF) + ((c >> 8) & 0x00FF00FF);
    // c = (c & 0x0000FFFF) + ((c >> 16)& 0x0000FFFF);

    // Explanation:
    // So if I have number 395 in binary 0000000110001011 (0 0 0 0 0 0 0 1 1 0 0 0 1 0 1 1)
    // After the first step I have:      0000000101000110 (0+0 0+0 0+0 0+1 1+0 0+0 1+0 1+1) = 00 00 00 01 01 00 01 10
    // In the second step I have:        0000000100010011 ( 00+00   00+01   01+00   01+10 ) = 0000 0001 0001 0011
    // In the fourth step I have:        0000000100000100 (   0000+0001       0001+0011   ) = 00000001 00000100
    // In the last step I have:          0000000000000101 (       00000001+00000100       )

	return c;
}
