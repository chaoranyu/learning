#include <stdio.h>

tyepdef struct myst {
    unsigned int a;
    unsigned int b;
} test_t;

int main(void)
{
    test_t x = {8, 9};
    test_t y = {3, 1};
    x -= y;

    printf("a = %u, b = %u\n", x.a, x.b);
    return 0;
}
