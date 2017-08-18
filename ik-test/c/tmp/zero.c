#include <stdio.h>

#define TEST_MIN  0
#define TEST_MAX  9

int main()
{
    int i = 0, j = 3, k = 9, l = 100;

    if (i < TEST_MIN || i > TEST_MAX)
        printf("i = %d, illegal!\n", i);
    else
        printf("i = %d, legal!\n", i);

    if (j < TEST_MIN || j > TEST_MAX)
        printf("j = %d, illegal!\n", j);
    else
        printf("j = %d, legal!\n", j);

    if (k < TEST_MIN || k > TEST_MAX)
        printf("k = %d, illegal!\n", k);
    else
        printf("k = %d, legal!\n", k);

    if (l < TEST_MIN || l > TEST_MAX)
        printf("l = %d, illegal!\n", l);
    else
        printf("l = %d, legal!\n", l);

    return 0;
}
