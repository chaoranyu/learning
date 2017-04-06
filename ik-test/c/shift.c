#include <stdio.h>

void main()
{
    unsigned u_num = 0xFC000033;
    printf("0x%x\t0x%x\n", u_num, u_num >> 8);

    int num = 0xFC000033;
    printf("0x%x\t0x%x\n", num, num >> 8);
}
