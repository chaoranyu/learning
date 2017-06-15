#include <stdio.h>
#include <stdint.h>

#define TEST_NUM    INT32_MAX

int main()
{
    int a;
    double b;
    // int c;

    int i = 0;
    for (; i < TEST_NUM; i++)
    {
        b = i;
        a = b;
    
        if (a != i)
            fprintf(stderr, "%d\t%.50f\t%d\n", i , b, a);
        //else
        //    fprintf(stdout, "[hello] %d\t%.50f\t%d\n", i , b, a);
    }

    return 0;
}
