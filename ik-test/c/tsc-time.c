#include <stdio.h>
#include <stdint.h>

void main()
{
    uint64_t cur_tsc = 0x3366779911223344;

    uint32_t time_now = (cur_tsc >> 1) / 1000000000U;

    printf("0x%llx\t0x%x\t0x%x\n", cur_tsc, 1000000000U, time_now);
}
