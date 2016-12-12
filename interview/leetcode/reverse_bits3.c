#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0U;
	
    for (int i = 0; i < 31; i++) {
        ret |= n & 01;
        ret <<= 1;
        n >>= 1;
    }
    ret |= n & 01;
        
    return ret;
}


int main()
{
	uint32_t a = 0x12345678;
	printf("0x%x\t0x%x\n", a, reverseBits(a));

	uint32_t b = 0x11223344;
	printf("0x%x\t0x%x\n", b, reverseBits(b));

	uint32_t c = 0x80000000;
	printf("0x%x\t0x%x\n", c, reverseBits(c));

	return 0;
}
