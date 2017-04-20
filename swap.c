#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE  10

#define swap_a(a, b)    do {    \
        int tmp = a;            \
        a = b;                  \
        b = tmp;                \
    } while(0)

#define swap_b(a, b)    do {    \
        a = a ^ b;              \
        b = a ^ b;              \
        a = a ^ b;              \
    } while(0)

#define swap_c(a, b)    do { a ^= b ^= a ^= b; } while(0)

int main()
{
    int *arr = (int *)malloc(sizeof(int) * ARRAY_SIZE);
    //int arr[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = i;
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < ARRAY_SIZE - 1; i++)
        swap_a(arr[i], arr[i+1]);
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = i;
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < ARRAY_SIZE - 1; i++)
        swap_b(arr[i], arr[i+1]);
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = i;
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < ARRAY_SIZE - 1; i++)
        swap_c(arr[i], arr[i+1]);
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
