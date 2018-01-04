#include <stdio.h>

int
is_num_or_range(char *str)
{
    char *tmp = str;
    char c;
    int hyphen;

    while ((c = *tmp++) != '\0')
    {
        if (c >= '0' && c <= '9')
            continue;

        if (c == '-')
        {
            hyphen++;
            continue;
        }

        return 0;
    }

    return hyphen <= 1;
}

int
main(int argc, char **argv)
{
    if (argc > 1)
    {
        char *s = argv[1];
        printf("%s: %d\n", s, is_num_or_range(s));
    }

    return 0;
}
