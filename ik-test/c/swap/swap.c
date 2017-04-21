#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE  10000000

#define swap1(a, b) do {\
    /*typedef(a) tmp;*/    \
        int tmp;        \
        tmp = a;        \
        a = b;          \
        b = tmp;        \
    } while(0)

// There is a problem when &a == &b
#define swap2(a, b) do {\
        a = a ^ b;      \
        b = a ^ b;      \
        a = a ^ b;      \
    } while(0)

#define swap3(a, b) do { a ^= b ^= a ^= b;} while(0)

int main()
{
    //int arr[ARRAY_SIZE];
    int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        //srand(time(0)); //use current time as seed for random generator
        //arr[i] = rand();
        arr[i] = i; 
    }
    printf("Initial data:\t\tarr[%d]=%d arr[%d]=%d arr[%d]=%d arr[%d]=%d\n",
        0, arr[0], 1, arr[1], ARRAY_SIZE-2, arr[ARRAY_SIZE-2],
        ARRAY_SIZE-1, arr[ARRAY_SIZE-1]);

    clock_t start, finish;
    double total_time;

    // swap1 test
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = i; 
    }
    start = clock();

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        swap1(arr[i], arr[i+1]);
    }

    finish = clock();
    total_time = 1000 * (finish - start) / CLOCKS_PER_SEC;
    printf("swap 1: %.2f ms\t", total_time); 
    printf("arr[%d]=%d arr[%d]=%d arr[%d]=%d arr[%d]=%d\n",
        0, arr[0], 1, arr[1], ARRAY_SIZE-2, arr[ARRAY_SIZE-2],
        ARRAY_SIZE-1, arr[ARRAY_SIZE-1]);

    // swap2 test
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = i; 
    }
    start = clock();

    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        swap2(arr[i], arr[i+1]);
    }

    finish = clock();
    total_time = 1000 * (finish - start) / CLOCKS_PER_SEC;
    printf("swap 2: %.2f ms\t", total_time); 
    printf("arr[%d]=%d arr[%d]=%d arr[%d]=%d arr[%d]=%d\n",
        0, arr[0], 1, arr[1], ARRAY_SIZE-2, arr[ARRAY_SIZE-2],
        ARRAY_SIZE-1, arr[ARRAY_SIZE-1]);

    // swap3 test
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = i; 
    }
    start = clock();

    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        swap3(arr[i], arr[i+1]);
    }

    finish = clock();
    total_time = 1000 * (finish - start) / CLOCKS_PER_SEC;
    printf("swap 3: %.2f ms\t", total_time); 
    printf("arr[%d]=%d arr[%d]=%d arr[%d]=%d arr[%d]=%d\n",
        0, arr[0], 1, arr[1], ARRAY_SIZE-2, arr[ARRAY_SIZE-2],
        ARRAY_SIZE-1, arr[ARRAY_SIZE-1]);

    return 0;
}
