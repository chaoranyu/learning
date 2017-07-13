#include <stdio.h>
#include <inttypes.h>
// #include <stdint.h>

int main(void)
{
    static num = 10;
    const wnum = 20;
    printf("num = %lu\n", num);
    printf("wnum = %lu\n", wnum);

    return 0;
}
