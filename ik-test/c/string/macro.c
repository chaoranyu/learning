#include <stdio.h>
#include <string.h>

// #define IS_STR_EQUAL(str1,str2) (strncmp(str1, str2, strlen(str1)) == 0 ? 1 : 0)
// #define IS_STR_EQUAL(str1,str2) (!strncmp(str1, str2, sizeof(str1)))

// It is right, because sizeof(str2) == strlen(str2) + 1
// str2[sizeof(str2)] == '\0', str1[sizeof(str2)] == '\0' when equal
// str2[sizeof(str2)] == '\0', str1[sizeof(str2)] != '\0' when unequal
#define IS_STR_EQUAL(str1,str2) (!strncmp(str1, str2, sizeof(str2)))

#define IS_STR_EQUAL_TEST(str1,str2)                                \
    ({                                                              \
        int result;                                                 \
        result = !strncmp(str1, str2, sizeof(str2));                \
        printf("%u  %u  %u\n", sizeof(str1), sizeof(str2), result); \
        result;                                                     \
    })

int main()
{
    char str1[32] = "hello\0world";

    if (IS_STR_EQUAL(str1, "helloworld"))
        printf("equal\n");
    else
        printf("unequal\n");

    if (IS_STR_EQUAL(str1, "helloworld!"))
        printf("equal\n");
    else
        printf("unequal\n");

    if (IS_STR_EQUAL(str1, "hello"))
        printf("equal\n");
    else
        printf("unequal\n");

    char *str2 = "helloworld";
    char *str3 = "helloworld!";
    char *str4 = "hello";
    //printf("%u  %u  %u  %u\n", sizeof(str1), sizeof("helloworld"), sizeof("helloworld!"), sizeof("hello"));
    //printf("%u  %u  %u\n", 
    //        IS_STR_EQUAL(str1, "helloworld"),
    //        IS_STR_EQUAL(str1, "helloworld!"),
    //        IS_STR_EQUAL(str1, "hello"));

    return 0;
}
