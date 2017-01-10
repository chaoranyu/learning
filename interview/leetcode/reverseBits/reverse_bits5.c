#include <stdio.h>
#include <stdint.h>

uint32_t swapBits(uint32_t n, int i, int j)
{
	uint32_t a = (n >> i) & 1;
	uint32_t b = (n >> j) & 1;

	if (a ^ b == 1) {
		n ^= (1U << i) | (1U << j);
	}

	return n;
}

uint32_t reverseBits(uint32_t n)
{
    uint32_t t = sizeof(n) * 8;
	for (int i = 0; i < t / 2; i++) {
		n = swapBits(n, i, t - i - 1);
	}

    return n;
}

int main()
{
	uint32_t a = 0x87654321;
	printf("0x%x\t0x%x\n", a, reverseBits(a));

	uint32_t b = 0x12345678;
	printf("0x%x\t0x%x\n", b, reverseBits(b));

	return 0;
}
