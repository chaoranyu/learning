#include <stdio.h>
#include <string.h>

typedef void* (*memfunc)(void* dest, const void* src, size_t count); 
void test_memcopy(memfunc func, const char *func_name, int reverse);

int main()
{
    test_memcopy(memcpy, "memcpy", 0);
    test_memcopy(memcpy, "memcpy", 1);
    test_memcopy(memmove, "memmove", 0);
    test_memcopy(memmove, "memmove", 1);

    return 0;
}

void test_memcopy(memfunc func, const char *func_name, int reverse)
{
    int array_a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;

    printf("%s(3, 4, 6):\n\t", func_name);
    for (i = 0; i < sizeof(array_a) / sizeof(array_a[0]); i++)
        printf("%d  ", array_a[i]);
    printf("\n\t");

    if (!reverse)
        (*func)(&array_a[3], &array_a[4], 6 * sizeof(int));
    else
        (*func)(&array_a[4], &array_a[3], 6 * sizeof(int));

    for (i = 0; i < sizeof(array_a) / sizeof(array_a[0]); i++)
        printf("%d  ", array_a[i]);
    printf("\n");
}
