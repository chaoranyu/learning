#include <stdio.h>
#include <string.h>

static void echo(char *s);

void
echo(char *s)
{
    char l, *tmp = s;
    unsigned char u;

    fprintf(stdout, ">> ");

    while ((l = *tmp++) != '\0')
    {
        u = toupper(l);
        if (l != u)
            fprintf(stdout, "%c", u);
        else
            fprintf(stdout, "%c", l);
    }

    if (s[strlen(s)-1] != '\n')
        fprintf(stdout, "\n");
}

void
register_echo(void)
{
    typedef void test_cb_func(char *s);
    test_cb_func *cb = echo;

    register_cmd(cb);
}
