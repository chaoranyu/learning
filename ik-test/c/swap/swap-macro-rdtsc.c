#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define swap1(a, b) do {    \
    /*typeof(a) tmp;*/      \
        int tmp = (a);      \
        (a) = (b);          \
        (b) = tmp;          \
    } while(0)

// There is a problem when &a == &b
#define swap2(a, b) do {    \
        (a) ^= (b);    \
        (b) ^= (a);    \
        (a) ^= (b);    \
    } while(0)

// it's wrong when gcc -O0
#define swap3(a, b) do { (a) ^= (b) ^= (a) ^= (b); } while(0)

long long get_cycle_count();
void test1();
void test2();

int main()
{
    printf("======= 1. Correctness test =======\n");
    test1();
    printf("\n");

    printf("======= 2. Performance test =======\n");
    test2();
    printf("\n");

    return 0;
}

inline long long get_cycle_count() {
    long long hi, lo;  
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));  
    return ( (long long)lo)|( ((long long)hi)<<32 ); 
}  

void test1()
{
    int a, b;

    //////////////////// swap1 test
    printf("test1:\n");
    a = 0, b = 1;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap1(a, b);
    printf("a = %d, b=%d\n", a, b);

    a = 1, b = 9;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap1(a, b);
    printf("a = %d, b=%d\n", a, b);

    a = 4, b = 4;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap1(a, b);
    printf("a = %d, b=%d\n", a, b);

    //////////////////// swap2 test
    printf("test2:\n");
    a = 0, b = 1;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap2(a, b);
    printf("a = %d, b=%d\n", a, b);

    a = 1, b = 9;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap2(a, b);
    printf("a = %d, b=%d\n", a, b);

    a = 4, b = 4;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap2(a, b);
    printf("a = %d, b=%d\n", a, b);

    //////////////////// swap3 test
    printf("test3:\n");
    a = 0, b = 1;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap3(a, b);
    printf("a = %d, b=%d\n", a, b);

    a = 1, b = 9;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap3(a, b);
    printf("a = %d, b=%d\n", a, b);

    a = 4, b = 4;
    printf("\ta = %d, b=%d ---> ", a, b);
    swap3(a, b);
    printf("a = %d, b=%d\n", a, b);
}

void test2()
{
    const int ARRAY_SIZE = 50000000;

    int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = i; 

    int TEST_CNT = 5;
    long long ticks_start, ticks_end;
    long long total_time;

    //////////////////// swap1 test
    total_time = 0LL;
    for (int k = 0; k < TEST_CNT; k++)
    {
        ticks_start = get_cycle_count();

        for (int i = 0; i < ARRAY_SIZE - 1; i++)
            swap1(arr[i], arr[i+1]);

        ticks_end = get_cycle_count();

        total_time += ticks_end - ticks_start;
    }
    printf("swap 1: %lld ticks\n", total_time); 

    //////////////////// swap2 test
    total_time = 0LL;
    for (int k = 0; k < TEST_CNT; k++)
    {
        ticks_start = get_cycle_count();

        for (int i = 0; i < ARRAY_SIZE - 1; i++)
            swap1(arr[i], arr[i+1]);

        ticks_end = get_cycle_count();

        total_time += ticks_end - ticks_start;
    }
    printf("swap 2: %lld ticks\n", total_time); 

    //////////////////// swap3 test
    total_time = 0LL;
    for (int k = 0; k < TEST_CNT; k++)
    {
        ticks_start = get_cycle_count();

        for (int i = 0; i < ARRAY_SIZE - 1; i++)
            swap1(arr[i], arr[i+1]);

        ticks_end = get_cycle_count();

        total_time += ticks_end - ticks_start;
    }
    printf("swap 3: %lld ticks\n", total_time); 
}
