/* gcc prime.c -std=c99 -lm */
#include <stdio.h>
#include <math.h>

#define LOOK_COUNT  1000
int is_prime(unsigned num)
{
    for (unsigned i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0; 
        }
    }

    return 1;
}

int main()
{
    fflush(stdin);

    unsigned int n;
    scanf("%d", &n);
    for (unsigned i = 0; i < LOOK_COUNT; i++)
    {
        if (is_prime(n) != 0)
        {
            printf("%u is prime\n", n);
            return 0; 
        }
        n++;
    }
    printf("not found a prime\n");

    return 0;
}
