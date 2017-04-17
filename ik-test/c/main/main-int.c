#include <stdio.h>

int main()
{
    int m = 0x12341234;
    int n = 0x56785678;

    int *a = &n;
    int *b = &n;
    int *c = &n;
    printf("0x%x\t0x%x\t0x%x\n", a, b, c);
    printf("0x%x\n", sizeof(int *));

    return 0;
}
