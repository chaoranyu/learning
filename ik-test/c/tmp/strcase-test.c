#include <stdio.h>
#include <stdint.h>
#include <string.h>


int main()
{
    char *s1 = "ABC1234560D";
    char *s2 = "abc1234560d";
    char *s3 = "12@abc1234560Defg";
    char *se = "";

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);
    printf("se: %s\n", se);

    printf("s1 == s2 ? %u\n", strcasecmp(s1, s2));
    printf("s2 in s3 ? %s\n", strcasestr(s3, s2));
    printf("se in s3 ? %s\n", strcasestr(se, s2));

    printf("tolower(A) = %c\n", tolower('A'));
    printf("tolower(0) = %c\n", tolower('0'));
    printf("tolower(]) = %c\n", tolower(']'));
    printf("tolower(\\t) = %u\n", tolower('\t'));

    return 0;
}
