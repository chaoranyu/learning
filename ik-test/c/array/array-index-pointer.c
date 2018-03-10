#include <stdio.h>

#define TEST_COUNT  (1000U)
#define ARRAY_SIZE  (1000000U)

inline long long get_cycle_count() {
    long long hi, lo;   
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));  
    return ( (long long)lo)|( ((long long)hi)<<32 );
} 

int
main(void)
{
    long long ticks_start, ticks_end;
    int array_a[ARRAY_SIZE], i, c;

    ticks_start = get_cycle_count();
    /* It is very fast under gcc -O3. */
    for (c = 0; c < TEST_COUNT; c++)
    {
        for (i = 0; i < ARRAY_SIZE; i++)
        {
            array_a[i] = 0;
        }
    }

    ticks_end = get_cycle_count();
    printf("array index use %lld ticks\n", ticks_end - ticks_start);

    int array_b[ARRAY_SIZE], *ap;

    ticks_start = get_cycle_count();
    /* It is still slow under gcc -O3. */
    for (c = 0; c < TEST_COUNT; c++)
    {
        for (ap = array_b; ap < array_b + ARRAY_SIZE; ap++)
        {
            *ap = 0;
        }
    }

    ticks_end = get_cycle_count();
    printf("array pointer use %lld ticks\n", ticks_end - ticks_start);

    return 0;
}
