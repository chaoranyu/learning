#include <stdio.h>

typedef struct {
    int a;
    int b;
} num_test_t;

typedef struct {
    num_test_t *num;
    char *s;
} my_test_t;


int main()
{
    num_test_t num_test;
    num_test.a = 1;
    num_test.b = 2;

    my_test_t my_test;
    my_test.num = &num_test;
    my_test.s = "hello, world";

    printf("a = %d, b = %d, s = %s\n", my_test.num->a, my_test.num->b, my_test.s);

    return 0;
}
