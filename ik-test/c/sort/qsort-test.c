/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

#define SORT_NUM    4

//int values[] = { 40, 10, 100, 90, 20, 25 };
unsigned int values[] = { 16842752, 3232235520, 16846592, 0x80000001 };

int compare (const void * a, const void * b)
{
    //return ( *(int*)a - *(int*)b );
    //return ( *(unsigned int*)a - *(unsigned int*)b );
    return ( *(unsigned int*)a > *(unsigned int*)b );
}

int main ()
{
    int n;
    for (n=0; n<SORT_NUM; n++)
        printf ("%u ",values[n]);
    printf("\n");

    qsort (values, SORT_NUM, sizeof(unsigned int), compare);
    for (n=0; n<SORT_NUM; n++)
        printf ("%u ",values[n]);
    printf("\n\n");

    return 0;
}
