#include <stdio.h>
#include <stdlib.h>

void * malloc_test(size_t size)
{
    return malloc(size);
}

int test()
{
    int *x = malloc_test(sizeof(int));

    *x = 333;

    printf("%d\n", *x);

    return 0;
}
