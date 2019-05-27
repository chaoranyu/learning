#include <stdio.h>
#include <string.h>

typedef void* (*memfunc)(void* dest, const void* src, size_t count); 
void test_memcopy(memfunc func, int reverse);

int main()
{
    printf("memcpy(3, 4, 6):\n\t");
    test_memcopy(memcpy, 0);

    printf("memcpy(4, 3, 6):\n\t");
    test_memcopy(memcpy, 1);

    printf("memmove(3, 4, 6):\n\t");
    test_memcopy(memmove, 0);

    printf("memmove(4, 3, 6):\n\t");
    test_memcopy(memmove, 1);

    return 0;
}

void test_memcopy(memfunc func, int reverse)
{
    int array_a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;

    for (i = 0; i < 10; i++)
        printf("%d  ", array_a[i]);
    printf("\n\t");

    if (!reverse)
        (*func)(&array_a[3], &array_a[4], 6 * sizeof(int));
    else
        (*func)(&array_a[4], &array_a[3], 6 * sizeof(int));

    for (i = 0; i < 10; i++)
        printf("%d  ", array_a[i]);
    printf("\n");
}
