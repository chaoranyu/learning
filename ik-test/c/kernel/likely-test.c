/* #if __GNUC__ >= 3
 * # define __glibc_unlikely(cond) __builtin_expect((cond), 0)
 * # define __glibc_likely(cond) __builtin_expect((cond), 1)
 * #else
 * # define __glibc_unlikely(cond) (cond)
 * # define __glibc_likely(cond) (cond)
 * #endif
 * */

/* gcc -c -O3 -std=gnu11 likely-test.c */
#include <stdio.h>

#define likely(x)    __builtin_expect((x), 1)
#define unlikely(x)  __builtin_expect((x), 0)

int main()
{
    int a = 3, b = -5;

    if (likely(a > 0))
        printf("a > 0\n");
    else
        printf("a <= 0\n");

    if (unlikely(b > 0))
        printf("b > 0\n");
    else
        printf("b <= 0\n");

    return 0;
}

