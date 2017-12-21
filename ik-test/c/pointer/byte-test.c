#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_ip_bit(unsigned int ip)
{
    printf("%u.%u.%u.%u\n", ip >> 24, (ip >> 16) & 0xFF,
            (ip >> 8) & 0xFF, ip & 0xFF);
}

void print_ip_pointer(unsigned int ip)
{
    printf("%u.%u.%u.%u\n",
            ((unsigned char *)&ip)[3], ((unsigned char *)&ip)[2],
            ((unsigned char *)&ip)[1], ((unsigned char *)&ip)[0]);
}

void test_performance();

int main()
{
    printf("======= 1. Correctness test =======\n");
    unsigned int ip = 0xC0A80001; // 192.168.0.1 
    print_ip_bit(ip);
    print_ip_pointer(ip);
    printf("\n");

    printf("======= 2. Performance test =======\n");
    test_performance();
    printf("\n");

    return 0;
}

void test_performance()
{
    const int ARRAY_SIZE = 50000000;

    int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = i; 

    int TEST_CNT = 5;
    clock_t start, finish;
    double total_time;

    //////////////////// test one
    total_time = 0.0f;

    for (int k = 0; k < TEST_CNT; k++)
    {
        start = clock();

        for (int i = 0; i < ARRAY_SIZE - 1; i++)
        {
            arr[i] >> 24;
            (arr[i] >> 16) & 0xFF;
            (arr[i] >> 8) & 0xFF;
            arr[i] & 0xFF;
        }

        finish = clock();
        total_time += 1000 * (finish - start) / CLOCKS_PER_SEC;
    }
    printf("test 1: %.2f ms\n", total_time/TEST_CNT); 

    //////////////////// test two
    total_time = 0.0f;
    for (int k = 0; k < TEST_CNT; k++)
    {
        start = clock();

        for (int i = 0; i < ARRAY_SIZE - 1; i++)
        {
            ((unsigned char *)&arr[i])[3];
            ((unsigned char *)&arr[i])[2];
            ((unsigned char *)&arr[i])[1];
            ((unsigned char *)&arr[i])[0];
        }

        finish = clock();
        total_time += 1000 * (finish - start) / CLOCKS_PER_SEC;
    }
    printf("test 2: %.2f ms\n", total_time/TEST_CNT); 
}
