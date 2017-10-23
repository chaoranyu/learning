#include <stdio.h>

typedef enum {
    TEST_MINUS_2 = -2,
    TEST_MINUS_1 = -1,
    TEST_ZERO = 0,
    TEST_POSITIVE_1 = 1,
    TEST_POSITIVE_2 = 2
} TestEnum;

int main()
{
    //TestEnum test;
    printf("%d\t", TEST_MINUS_2);
    printf("%d\t", TEST_MINUS_1);
    printf("%d\t", TEST_ZERO);
    printf("%d\t", TEST_POSITIVE_1);
    printf("%d\n", TEST_POSITIVE_2);

    printf("%u\t", TEST_MINUS_2);
    printf("%u\t", TEST_MINUS_1);
    printf("%u\t", TEST_ZERO);
    printf("%u\t", TEST_POSITIVE_1);
    printf("%u\n", TEST_POSITIVE_2);

    return 0;
}
