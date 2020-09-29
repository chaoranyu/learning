#include <stdio.h>
#include <stdint.h>
#include <string.h>
//#include <stdlib.h>
//#include <unistd.h>

enum {
    E_OK         = 0,
    E_BADARG     = 1, /* Bip argument. */
    E_NOMEM      = 2, /* No memory. */
    E_BADIP      = 3, /* Not expected ip string. */
    E_BADNUM     = 4, /* Not expected integer string. */
    E_BADSTR     = 5, /* Not expected other string. */

    E_FAILED     = 255
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

int32_t str_util_atoi_range(const char *s, uint32_t range[], uint32_t *num)
{
    if (NULL == s || NULL == range || NULL == num)
        return E_BADARG;

    unsigned char c;
    char *tmp, *cur, *input;
    char str[INT_RANGE_STR_LEN] = { 0 };
    uint32_t ns, ne, is_range, i, n = 0;

    input = str;
    strncpy(str, s, sizeof(str));
    str[sizeof(str) - 1] = '\0';

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
                    return E_BADNUM;

                is_range = 1;
                break;
            }

            if (c < '0' || c > '9')
                return E_BADNUM;
            c -= '0';

            if (ns > UINT32_MAX / 10 || (ns == UINT32_MAX / 10 && c > UINT32_MAX % 10))
                return E_BADNUM;

            ns = ns * 10 + c;
        }

        if (is_range)
        {
            ne = 0;

            while ((c = *tmp++) != '\0')
            {
                if (c < '0' || c > '9')
                    return E_BADNUM;
                c -= '0';

                if (ne > UINT32_MAX / 10 || (ne == UINT32_MAX / 10 && c > UINT32_MAX % 10))
                    return E_BADNUM;

                ne = ne * 10 + c;
            }

            if (ns > ne)
                return E_BADNUM;
        }
        else
        {
            ne = ns;
        }

        if (ns > ne)
        {
            return E_BADNUM;
        }

        for (i = ns; i <= ne && n < *num; i++)
        {
            *range++ = i;
            n++;

            if (n > INT_RANGE_ARRAY_SIZE)
                return E_BADNUM;
        }
    }

    *num = n;

    return E_OK;
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
	const char *s3 = "1-4,6,9";
	uint32_t a, b, c, d, mask;
	uint32_t array[INT_RANGE_ARRAY_SIZE];
	uint32_t i, num;
	int32_t ret;

	ret = str_util_atoi(s, &a);
	if (ret)
		printf("Test str_util_atoi: failed(%d).\n", ret);
	else
		printf("Test str_util_atoi: string = %s, num = %u\n", s, a);

	ret = str_util_pton(s1, &b);
	if (ret)
		printf("Test str_util_pton: failed(%d).\n", ret);
	else
		printf("Test str_util_pton: string = %s, ip = 0x%x\n", s1, b);

	ret = str_util_ptoh(s1, &c);
	if (ret)
		printf("Test str_util_ptoh: failed(%d).\n", ret);
	else
		printf("Test str_util_ptoh: string = %s, ip = 0x%x\n", s1, c);

	ret = str_util_ptoh_mask(s2, &d, &mask);
	if (ret)
		printf("Test str_util_ptoh_mask: failed(%d).\n", ret);
	else
		printf("Test str_util_ptoh_mask: string = %s, ip = 0x%x, mask = %u\n",
			s2, d, mask);

	ret = str_util_atoi_range(s3, array, &num);
	if (ret)
		printf("Test str_util_atoi: failed(%d).\n", ret);
	else
	{
		printf("Test str_util_atoi: string = %s, num =", s3);
		for (i = 0; i < num; i++)
			printf(" %u", array[i]);
		printf("\n");
	}

	return 0;
}
