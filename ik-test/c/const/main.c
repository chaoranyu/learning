#include <stdio.h>
#include <string.h>

typedef struct {
    int *a;
    int *b;
} test_t;

const int* const test(test_t *te)
{
    return te->a;
}

void main()
{
    test_t *t;
    t = (test_t*)malloc(sizeof(test_t));
    t->a = (int *)malloc(sizeof(int));
    t->b = (int *)malloc(sizeof(int));
    *(t->a) = 3;
    *(t->b) = 6;
    printf("%d  %d\n", *t->a, *t->b);

    int *p = test(t);
    *p = 2;
    printf("%d  %d\n", *t->a, *t->b);
}
