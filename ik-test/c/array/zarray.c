#include <stdio.h>

typedef struct {
    int a;
    int v[10];
} TEST_T;

int
main()
{
    TEST_T a, b;
    int i = 0;

    a.a = 1;
    for (i = 0; i < 10; i++)
        a.v[i] = i * i;

    b = a;
    printf("b.a = %d\n", b.a);
    printf("b.v = ");
    for (i = 0; i < 10; i++)
        printf("%d\t", b.v[i]);

    printf("\n-----------------\n");

    for (i = 0; i < 10; i++)
        a.v[i] = i;

    printf("a.a = %d\n", a.a);
    printf("a.v = ");
    for (i = 0; i < 10; i++)
        printf("%d\t", a.v[i]);

    printf("\n-----------------\n");

    printf("b.a = %d\n", b.a);
    printf("b.v = ");
    for (i = 0; i < 10; i++)
        printf("%d\t", b.v[i]);

    printf("\n");

    return 0;
}
