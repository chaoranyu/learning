#include <stdio.h>


typedef void test_cb_func(char *s);

static test_cb_func *gtest;

void
register_cmd(test_cb_func *cb)
{
    gtest = cb;
}

int
main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: a.out string\n");
        return -1;
    }

    extern void register_echo(void);
    register_echo();

    gtest(argv[argc-1]);

    /* test */
#if 0
    extern void echo(char *s);
    echo(argv[argc-1]);
#endif

    return 0;
}
