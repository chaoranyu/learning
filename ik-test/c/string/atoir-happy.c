#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* bool typedef */
#ifndef bool
typedef int32_t bool;
#define FALSE   0
#define TRUE    1
#endif

static bool atoir_happy(char *s, uint32_t *num_start, uint32_t *num_end);

int
main()
{
    char s[255] = { 0 };
    uint32_t num_start, num_end;

    scanf("%s", s);

    if (atoir_happy(s, &num_start, &num_end) == TRUE)
    {
        printf("num_start = %u, num_end = %u\n", num_start, num_end);
        return 0;
    }
    else
    {
        printf("invalid input\n");
        return 1;
    }
}

static bool
atoir_happy(char *s, uint32_t *num_start, uint32_t *num_end)
{
    if (s == NULL || num_start == NULL || num_end == NULL)
        return FALSE;

    unsigned char c;
    uint32_t ns = 0, ne = 0, is_range = 0;
    while ((c = *s++) != '\0')
    {
        if (c == '-')
        {
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
        while ((c = *s++) != '\0')
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

        *num_start = ns;
        *num_end = ne;
    }
    else
    {
        *num_start = ns;
        *num_end = ns;
    }

    return TRUE;
}
