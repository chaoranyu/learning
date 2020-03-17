#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TEST_NUM    200000

const char rdkeys[37] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1',
    '2', '3', '4', '5', '6', '7', '8', '9', '-'};

unsigned int BKDRHash(char *str);

int main()
{
    int i, j, k, level, len, c;
    char s[256];
    int len_s;

    srand(time(NULL));

    for (i = 0; i < TEST_NUM; i++)
    {
        len_s = 0;
        memset(s, 0, sizeof(s));

        level = rand() % 3 + 1;

        for (j = 0; j < level - 1; j++)
        {
            len = rand() % 6 + 1;
            for (k = 0; j < len; j++)
            {
                c = rand() % 37;
                c = rdkeys[c];
                len_s += snprintf(s + len_s, 256, "%c", (char)c);
            }

            len_s += snprintf(s + len_s, 256, "%c", '.');
        }

        /* top domain */
        for (k = 0; k < 3; k++)
        {
            c = rand() % 26;
            c = rdkeys[c];
            len_s += snprintf(s + len_s, 256, "%c", (char)c);
        }

        fprintf(stdout, "%s %u\n", s, BKDRHash(s));
    }

    return 0;
}

// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    //return (hash & 0x7FFFFFFF);
    return (hash & 0x7FFFFF); // 200000 --> 8388608
}
