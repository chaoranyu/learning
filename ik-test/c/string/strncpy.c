#include <stdio.h>
#include <string.h>

int main()
{
    char s1[32] = "hello";
    char s2[32] = "are you OK";

    char *s = strcpy(s2, s1);
    printf("s1: %p, s2: %p, s: %p\n", s1, s2, s);
    printf("s1: %s, s2: %s\n", s1, s2);

    return 0;
}
