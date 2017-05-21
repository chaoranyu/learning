#include <stdio.h>
#include <stdlib.h>

typedef struct test
{
    int a;
    int b;
    char c;
} test_t;

main() {
    printf("size of struct test_t is %d\n", sizeof(test_t));

    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    test_t *tmp = &test[4];

    printf("%d\n", tmp - test);
}
