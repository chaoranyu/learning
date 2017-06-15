#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* bool typedef */
#ifndef bool
typedef int32_t bool;
#define FALSE   0
#define TRUE    1
#endif

static bool atoi_happy(char *s, uint32_t *num);

int
main()
{
    uint32_t num;
    char s[255];
    scanf("%s", s);

    if (atoi_happy(s, &num) == TRUE)
    {
        printf("num = %u\n", num);
        return 0;
    }
    else
    {
        printf("invalid input\n");
        return 1;
    }
}

static bool
atoi_happy(char *s, uint32_t *num)
{
    const uint32_t STR_LENGTH = 10;

    if (s == NULL || num == NULL)
        return FALSE;

    if (strlen(s) > STR_LENGTH)
        return FALSE;

    char c;
    uint32_t n = 0;
    while ((c = *s++) != '\0')
    {
        if (c < '0' || c > '9')
            return FALSE;
        c -= '0';

        if (n > UINT32_MAX / 10 || n == UINT32_MAX / 10 && c > UINT32_MAX % 10)
            return FALSE;

        n = n * 10 + c;
    }
    //while ((c = *s++) != '\0')
    //{
    //    if (c < '0' || c > '9')
    //        return FALSE;

    //    // n = n * 10 + c & 0xF;
    //    n = n * 10 + c - '0';
    //}

    *num = n;

    return TRUE;
}
