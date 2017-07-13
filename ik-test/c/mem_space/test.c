#include <stdio.h>
#include <stdlib.h>

int a = 3;
char *s1;

int main()
{
    static int b = 6;
    int c = 9;
    char *p = (char *)malloc(10);
    char *s2 = "hello, world";

    printf("a: %p\nb: %p\nc: %p\np: %p\n&s1: %p\ns2: %p\n", &a, &b, &c, p, &s1, s2);

    return 0;
}
