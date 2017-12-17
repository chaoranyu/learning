#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *s1;
    char *s2;
} test_t;

test_t test = {
    .s1 = "111",
    .s2 = "222"
};

int
main(void)
{
    printf("s1: %s\n", test.s1);
    printf("s2: %s\n", test.s2);

    return 0;
}
