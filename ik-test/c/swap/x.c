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

int main()
{
    //////////////////// swap1 test
    const int ARRAY_SIZE = 50000000;

    int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    //for (int i = 0; i < ARRAY_SIZE; i++)
    //    arr[i] = i; 

    // clock_t start, finish;
    // double total_time;

    //////////////////// swap1 test
    // total_time = 0.0f;

    // start = clock();

    for (int i = 0; i < ARRAY_SIZE - 1; i++)
        swap1(arr[i], arr[i+1]);

    // finish = clock();
    // total_time = 1000 * (finish - start) / CLOCKS_PER_SEC;
    //total_time = (finish - start) / 1000;

    // printf("swap 1: %.2f ms\n", total_time); 

    //////////////////// swap1 test
    // total_time = 0.0f;

    // start = clock();

    for (int i = 0; i < ARRAY_SIZE - 1; i++)
        swap2(arr[i], arr[i+1]);

    // finish = clock();
    // total_time = 1000 * (finish - start) / CLOCKS_PER_SEC;
    //total_time = (finish - start) / 1000;

    // printf("swap 2: %.2f ms\n", total_time); 

    return 0;
}
