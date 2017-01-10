#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
	int c = 0;

	while (n != 0) {
		ret <<= 1;
		ret |= n & 1;
		n >>= 1;
		c++;
	}
	ret <<= 32 - c;

    return ret;
}

int main()
{
	uint32_t a = 0x87654321;
	printf("0x%x\t0x%x\n", a, reverseBits(a));

	uint32_t b = 0x10000000;
	printf("0x%x\t0x%x\n", b, reverseBits(b));

	return 0;
}
