#include <stdio.h>
#include <stdint.h>

#define TEST_NUM    INT32_MAX / TIME_DIVISIOR
#define TIME_DIVISIOR  100

int main()
{
    int n;
    double d;
    // int c;

    int i = 0;
    for (; i < TEST_NUM; i++)
    {
        d = i;
        // n = ((int)d) * TIME_DIVISIOR;
        n = d * TIME_DIVISIOR; // not ok
    
        if (n != i * TIME_DIVISIOR)
            fprintf(stderr, "%d\t%.50f\t%d\n", i , d, n);
        //else
        //    fprintf(stdout, "[hello] %d\t%.50f\t%d\n", i , d, n);
    }

    return 0;
}
