#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0U;
    int b;
    
//    for (b = 0; n; n >>= 1) {
//        ret |= n & 01;
//        ret <<= 1;
//		b++;
//    }
//	ret <<= 31 - b;
        
    for (b = 0; b < 31; b++) {
        ret |= n & 01;
        ret <<= 1;
        n >>= 1;
    }
        
    return ret;
}


int main()
{
	uint32_t a = 0x12345678;
	printf("0x%x\t0x%x\n", a, reverseBits(a));

	uint32_t b = 0x10000000;
	printf("0x%x\t0x%x\n", b, reverseBits(b));

	return 0;
}
