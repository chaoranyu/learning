#include <stdio.h>

int main()
{
    unsigned old = 0xFFFFFFFF;
    unsigned new = old + 5;

    printf("new = %u, old = %u, new - old = %u\n", new, old, new - old);

    return 0;
}
