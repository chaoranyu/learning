#include <stdio.h>

#define ARRAY_SIZE  8

/* Both statements are right */
typedef int mytype[ARRAY_SIZE];
//typedef int mytype [ARRAY_SIZE];

int main()
{
    mytype test;
    printf("sizeof(test) = %d\n", sizeof(mytype));

    int a[ARRAY_SIZE];
    printf("%p   %p\n", a, &a);

    return 0;
}
