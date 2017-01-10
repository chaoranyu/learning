#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
	n = (n >> 16) | (n << 16);
	n = ((n & 0xFF00FF00) >> 8) |  ((n & 0x00FF00FF) << 8);
	n = ((n & 0xF0F0F0F0) >> 4) |  ((n & 0x0F0F0F0F) << 4);
	n = ((n & 0xCCCCCCCC) >> 2) |  ((n & 0x33333333) << 2);
	n = ((n & 0xAAAAAAAA) >> 1) |  ((n & 0x55555555) << 1);

//	assert(sizeof(n) == 4); // special case: only works for 4 bytes (32 bits).
//	n = ((n & 0n55555555) << 1) | ((n & 0nAAAAAAAA) >> 1);
//	n = ((n & 0n33333333) << 2) | ((n & 0nCCCCCCCC) >> 2);
//	n = ((n & 0n0F0F0F0F) << 4) | ((n & 0nF0F0F0F0) >> 4);
//	n = ((n & 0n00FF00FF) << 8) | ((n & 0nFF00FF00) >> 8);
//	n = ((n & 0n0000FFFF) << 16) | ((n & 0nFFFF0000) >> 16);

    return n;
}

int main()
{
	uint32_t a = 0x87654321;
	printf("0x%x\t0x%x\n", a, reverseBits(a));

	uint32_t b = 0x10000000;
	printf("0x%x\t0x%x\n", b, reverseBits(b));

	return 0;
}
