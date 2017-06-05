#include <stdio.h>
#include <string.h>

#define IS_STR_EQUAL(str1,str2) (strncmp(str1, str2, strlen(str1)) == 0 ? 1 : 0)

int main()
{
    char *str1 = "hello";
    char *str2 = "world";
    char *str3 = "hello";
    char *str4 = "Hello";

    if (IS_STR_EQUAL(str1, str2))
        printf("equal\n");
    else
        printf("unequal\n");

    if (IS_STR_EQUAL(str1, str3))
        printf("equal\n");
    else
        printf("unequal\n");

    if (IS_STR_EQUAL(str1, str4))
        printf("equal\n");
    else
        printf("unequal\n");

    return 0;
}
