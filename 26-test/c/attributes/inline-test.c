// gcc -S inline-test.c

#include <stdio.h>
#include <stdlib.h>

inline __attribute__((always_inline)) int sum(int a, int b)
{
    return (a + b);
}

inline int sum2(int a, int b)
{
    return (a + b);
}

int main(int argc, char *argv[])
{
    int a = 3;
    int b = 5;

    printf("%d + %d = %d\n", a, b, sum(a, b));
    printf("%d + %d = %d\n", a, b, sum2(a, b));

    return 0;
}
