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

void test1();
void test2();

int main()
{
    printf("======= 1. Correctness test =======\n");
    test1(); /* Too much duplicate code, think more. */
    printf("\n");

    printf("======= 2. Performance test =======\n");
    test2(); /* Too much duplicate code, think more. */
    printf("\n");

    return 0;
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
    const int ARRAY_SIZE = 100000000;

    int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = i; 

    int TEST_CNT = 5;
    time_t start, finish;
    time_t total_time;

    //////////////////// swap1 test
    total_time = 0;
    for (int k = 0; k < TEST_CNT; k++)
    {
        start = time(NULL);

        for (int i = 0; i < ARRAY_SIZE - 1; i++)
            swap1(arr[i], arr[i+1]);

        finish = time(NULL);
        total_time += finish - start;
    }
    printf("swap 1: %.2f s\n", (float)total_time/TEST_CNT); 

    //////////////////// swap2 test
    total_time = 0;
    for (int k = 0; k < TEST_CNT; k++)
    {
        start = time(NULL);

        for (int i = 0; i < ARRAY_SIZE - 1; i++)
            swap2(arr[i], arr[i+1]);

        finish = time(NULL);
        total_time += finish - start;
    }
    printf("swap 2: %.2f s\n", (float)total_time/TEST_CNT); 

    //////////////////// swap3 test
    total_time = 0;
    for (int k = 0; k < TEST_CNT; k++)
    {
        start = time(NULL);

        for (int i = 0; i < ARRAY_SIZE - 1; i++)
            swap3(arr[i], arr[i+1]);

        finish = time(NULL);
        total_time += finish - start;
    }
    printf("swap 3: %.2f s\n", (float)total_time/TEST_CNT); 
}
