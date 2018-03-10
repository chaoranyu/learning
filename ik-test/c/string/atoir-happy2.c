#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* bool typedef */
#ifndef bool
typedef int32_t bool;
#define FALSE   0
#define TRUE    1
#endif

#define RANGE_STR_LEN   (256U)
#define RANGE_MAX_NUM   (256U)

static bool atoir_happy2(char *s, uint32_t *range, uint32_t *num);

int
main()
{
    char s[255] = { 0 };
    uint32_t range[RANGE_STR_LEN], num, i;

    scanf("%s", s);

    if (atoir_happy2(s, range, &num) == FALSE)
    {
        printf("invalid input\n");
        return 1;
    }

    for (i = 0; i < num; i++) 
        printf("%u\t", range[i]);
    printf("\n\n");

    return 1;
}

static bool
atoir_happy2(char *s, uint32_t *range, uint32_t *num)
{
    if (s == NULL || range == NULL || num == NULL)
        return FALSE;

    unsigned char c;
    char *tmp, *cur, *input;
    char str[RANGE_STR_LEN] = { 0 };
    uint32_t ns, ne, is_range, i, n = 0;

    input = str;
    strncpy(str, s, sizeof(str));

    while ((cur = strsep(&input, ",")) != NULL)
    {
        tmp = cur;
        ns = 0;
        is_range = 0;

        while ((c = *tmp++) != '\0')
        {
            if (c == '-')
            {
                if (tmp - cur <= 1)
                    return FALSE;

                is_range = 1;
                break;
            }

            if (c < '0' || c > '9')
                return FALSE;
            c -= '0';

            if (ns > UINT32_MAX / 10 || (ns == UINT32_MAX / 10 && c > UINT32_MAX % 10))
                return FALSE;

            ns = ns * 10 + c;
        }

        if (is_range)
        {
            ne = 0;

            while ((c = *tmp++) != '\0')
            {
                if (c < '0' || c > '9')
                    return FALSE;
                c -= '0';

                if (ne > UINT32_MAX / 10 || (ne == UINT32_MAX / 10 && c > UINT32_MAX % 10))
                    return FALSE;

                ne = ne * 10 + c;
            }

            if (ns > ne)
                return FALSE;
        }
        else
        {
            ne = ns;
        }

        if (ns > ne)
        {
            return FALSE;
        }

        for (i = ns; i <= ne; i++)
        {
            *range++ = i;
            n++;

            if (n > RANGE_MAX_NUM)
                return FALSE;
        }
    }

    *num = n;

    return TRUE;
}
