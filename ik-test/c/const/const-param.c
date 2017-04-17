#include <stdio.h>

typedef struct {
    int a;
    int *b;
} test_t;

void change_test(const test_t *test)
{
    test->a = 666;
}

void change_test2(test_t * const test)
{
    test->a = 666;
}

main()
{
    test_t *test = (test_t *)malloc(sizeof(test_t));
    test->a = 3;
    test->b = NULL;

    printf("%d\n", test->a);
    change_test2(test);
    change_test(test);
    printf("%d\n", test->a);
}
