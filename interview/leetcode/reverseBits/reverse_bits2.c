#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0U;

	for (int i = 0; i < 32; ++i)
		ret |= (((n >> i) & 1) << (31 - i));

    return ret;
}

int main()
{
	uint32_t a = 0x12345678;
	printf("0x%x\t0x%x\n", a, reverseBits(a));

	uint32_t b = 0x87654321;
	printf("0x%x\t0x%x\n", b, reverseBits(b));

	return 0;
}
