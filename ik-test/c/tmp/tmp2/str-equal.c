#include <stdio.h>
#include <string.h>

#define IS_STR_EQUAL_H(str1, str2)    (!strncmp(str1, str2, sizeof(str2)))

int
main()
{
    char s[32];
    scanf("%s", s);

    if (IS_STR_EQUAL_H(s, "hello"))
        printf("Equal\n");
    else
        printf("Unequal\n");

    printf("%d\n", sizeof("hello"));

    return 0;
}
