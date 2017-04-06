/* gcc prime.c -std=c99 -lm */
#include <stdio.h>
#include <math.h>

void main()
{
    fflush(stdin);

    unsigned int n;
    scanf("%d", &n);
    for (unsigned i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            printf("%u is not prime\n", n);
            return; 
        }
    }
    printf("%u is prime\n");
    return;
}
