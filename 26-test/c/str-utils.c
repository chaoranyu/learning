#include <stdio.h>
#include <stdint.h>
#include <string.h>
//#include <stdlib.h>
//#include <unistd.h>

enum
{
    E_OK = 0,
    E_BADARG = 1, /* Bip argument. */
    E_NOMEM = 2,  /* No memory. */
    E_BADIP = 3,  /* Not expected ip string. */
    E_BADNUM = 4, /* Not expected integer string. */
    E_BADSTR = 5, /* Not expected other string. */

    E_FAILED = 255
};

#define INT_RANGE_STR_LEN (256U)
#define INT_RANGE_ARRAY_SIZE (256U)

int32_t str_util_atoi(const char *s, uint32_t *num)
{
    uint8_t c;
    uint32_t n, len;

    if (NULL == s || NULL == num)
        return E_BADARG;

    len = strlen(s);
    if (len > 10 || len == 0)
        return E_BADNUM;

    n = 0;
    while ((c = *s++) != '\0')
    {
        if (c < '0' || c > '9')
            return E_BADNUM;
        c -= '0';

        if (n > UINT32_MAX / 10 || (n == UINT32_MAX / 10 && c > UINT32_MAX % 10))
            return E_BADNUM;

        n = n * 10 + c;
    }

    *num = n;

    return E_OK;
}

#define AD_RANGE_MAX_INT 65535

int32_t str_util_atoi_range(const char *s, uint32_t range[], uint32_t *num)
{
    if (NULL == s || NULL == range || NULL == num)
        return E_BADARG;

    uint32_t n = 0;
    unsigned char c;
    char *unit, *input;
    char str[INT_RANGE_STR_LEN] = {0};

    strncpy(str, s, sizeof(str));
    str[sizeof(str) - 1] = '\0';
    input = str;

#define AD_RANGE_START 0
#define AD_RANGE_HIT_MIN 1
#define AD_RANGE_HIT_DASH 2
#define AD_RANGE_HIT_MAX 3
#define AD_RANGE_HIT_END 4

    while ((unit = strsep(&input, ",")) != NULL)
    {
        uint32_t min = 0;
        uint32_t max = 0;
        uint32_t flags = AD_RANGE_START;

        while ((c = *unit++) != '\0')
        {
            if (AD_RANGE_START == flags)
            {
                if (c == '-')
                {
                    return E_BADNUM;
                }

                if (c < '0' || c > '9')
                    return E_BADNUM;

                min = min * 10 + (c - '0');
                flags = AD_RANGE_HIT_MIN;
            }
            else if (AD_RANGE_HIT_MIN == flags)
            {
                if (c == '-')
                {
                    flags = AD_RANGE_HIT_DASH;
                    continue;
                }

                if (c < '0' || c > '9')
                    return E_BADNUM;

                min = min * 10 + (c - '0');

                if (min > AD_RANGE_MAX_INT)
                    return E_BADNUM;
            }
            else if (AD_RANGE_HIT_DASH == flags)
            {
                if (c < '0' || c > '9')
                    return E_BADNUM;

                max = max * 10 + (c - '0');
                flags = AD_RANGE_HIT_MAX;
            }
            else
            {
                if (c < '0' || c > '9')
                    return E_BADNUM;

                max = max * 10 + (c - '0');

                if (max > AD_RANGE_MAX_INT)
                    return E_BADNUM;
            }
        }

        if (AD_RANGE_START == flags)
            return E_BADNUM;

        if (AD_RANGE_HIT_DASH == flags && max == 0)
            return E_BADNUM;

        if (AD_RANGE_HIT_DASH == flags || AD_RANGE_HIT_MIN == flags)
            max = min;

        uint32_t ui;
        for (ui = min; ui <= max && n < INT_RANGE_ARRAY_SIZE; ui++)
        {
            range[n++] = ui;
        }
    }

    *num = n;
    return E_OK;

#undef AD_RANGE_START
#undef AD_RANGE_HIT_MIN
#undef AD_RANGE_HIT_DASH
#undef AD_RANGE_HIT_MAX
#undef AD_RANGE_HIT_END
}

int32_t str_util_pton(const char *s, uint32_t *ip)
{
    uint8_t c;
    uint32_t n = 0, m = 0, i = 0;

    if (NULL == s || NULL == ip)
        return E_BADARG;

    if (strlen(s) == 0 || strlen(s) > 15)
    {
        return E_BADIP;
    }

    while ((c = *s++) != '\0')
    {
        if (c == '.')
        {
            if (*s < '0' || *s > '9')
                return E_BADIP;

            n |= m << 8 * i;
            i++;
            m = 0;
            continue;
        }

        if (c < '0' || c > '9')
            return E_BADIP;

        m = m * 10 + c - '0';
        if (m > 255)
            return E_BADIP;
    }

    if (i != 3)
        return E_BADIP;

    n |= m << 8 * i;

    *ip = n;
    return E_OK;
}

int32_t str_util_ptoh(const char *s, uint32_t *ip)
{
    uint8_t c;
    uint32_t n = 0, m = 0, i = 0;

    if (NULL == s || NULL == ip)
        return E_BADARG;

    if (strlen(s) == 0 || strlen(s) > 15)
    {
        return E_BADIP;
    }

    while ((c = *s++) != '\0')
    {
        if (c == '.')
        {
            if (*s < '0' || *s > '9')
                return E_BADIP;

            n = n << 8 | m;

            i++;
            m = 0;
            continue;
        }

        if (c < '0' || c > '9')
            return E_BADIP;

        m = m * 10 + c - '0';
        if (m > 255)
            return E_BADIP;
    }

    if (i != 3)
        return E_BADIP;

    n = n << 8 | m;

    *ip = n;
    return E_OK;
}

int32_t str_util_ptoh_mask(const char *s, uint32_t *ip, uint32_t *mask)
{
    uint32_t m, n;
    char *ip_str;
    char tmp_str[512];
    char *input;
    char delim[] = "/";

    if (NULL == s || NULL == ip || NULL == mask)
        return E_BADARG;

    strncpy(tmp_str, s, sizeof(tmp_str));
    input = tmp_str;
    ip_str = strsep(&input, delim);

    if (str_util_ptoh(ip_str, &m))
        return E_BADIP;

    if (str_util_atoi(input, &n))
        return E_BADSTR;

    *ip = m;
    *mask = n;

    return E_OK;
}

int main()
{
    const char *s = "96";
    const char *s1 = "1.2.3.4";
    const char *s2 = "1.2.3.0/24";
    uint32_t a, b, c, d, mask;
    uint32_t array[INT_RANGE_ARRAY_SIZE];
    uint32_t i, j, num;
    int32_t ret;

    ret = str_util_atoi(s, &a);
    if (ret)
        printf("Test str_util_atoi: failed(%d).\n", ret);
    else
        printf("Test str_util_atoi: string = \"%s\", num = %u\n", s, a);

    ret = str_util_pton(s1, &b);
    if (ret)
        printf("Test str_util_pton: failed(%d).\n", ret);
    else
        printf("Test str_util_pton: string = \"%s\", ip = 0x%x\n", s1, b);

    ret = str_util_ptoh(s1, &c);
    if (ret)
        printf("Test str_util_ptoh: failed(%d).\n", ret);
    else
        printf("Test str_util_ptoh: string = \"%s\", ip = 0x%x\n", s1, c);

    ret = str_util_ptoh_mask(s2, &d, &mask);
    if (ret)
        printf("Test str_util_ptoh_mask: failed(%d).\n", ret);
    else
        printf("Test str_util_ptoh_mask: string = \"%s\", ip = 0x%x, mask = %u\n",
               s2, d, mask);

    const char *s_array[] = {"2", "13", "3-5", "2,3,4", "2,4,6-9", "65536", "-", "-1", "1-", ",", ",1", "1,"};
    uint32_t times = sizeof(s_array) / sizeof(const char *);
    printf("Test str_util_atoi_range %u times:\n", times);

    for (i = 0; i < times; i++)
    {
        ret = str_util_atoi_range(s_array[i], array, &num);
        if (ret)
            printf("Test str_util_atoi_range: failed, string = \"%s\", ret = %d.\n", s_array[i], ret);
        else
        {
            printf("Test str_util_atoi_range: success, string = \"%s\", num =", s_array[i]);
            for (j = 0; j < num; j++)
                printf(" %u", array[j]);
            printf("\n");
        }
    }

    return 0;
}
