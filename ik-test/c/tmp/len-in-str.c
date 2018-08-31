#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    char test[512] = { 0 };
    char *s1 = "1234567890";
    char *s2 = "000";
    char *s3 = "abcdefghij";
    int offset, pos, len = 123;

    offset = sprintf(test, "%s", s1);
    pos = offset;
    offset += sprintf(test + offset, "%s%s", s2, s3);

    *(test + pos++) += len / 100;
    len %= 100;
    *(test + pos++) += len / 10;
    *(test + pos) += len % 10;

    printf("offset = %d, pos = %d\n", offset, pos);
    printf("%s\n", test);

    return 0;
}
