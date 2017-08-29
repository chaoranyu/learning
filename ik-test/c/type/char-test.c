#include <stdio.h>

int
main(void)
{
    char c = 0;
    unsigned char uc = 0XFF;

    printf("uc = %u\n", uc);

    c = uc;
    printf("c = %d\n", c);

    return 0;
}
