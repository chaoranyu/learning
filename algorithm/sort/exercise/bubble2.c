#include <stdio.h>

int* sort(int data[], int num);

void main()
{
    int a[10] = {3, 5, 1 ,9, 6, 4, 2, 8, 7, 10};
    int *p = NULL;
    p = sort(a, 10);

    for (int i = 0; i < 10 ; i++)
    {
        printf("%d  ", *(p+i));
    }
    printf("\n");
}

int* sort(int a[], int num)
{
     int temp, i ,j;
     for (i = 0; i < num; i++)
     {
          //for(int j = num - i - 1; j >= 0; j--)
          for(j = 0; j < num-1-i; j++)
          {
              if (a[j] > a[j+1])
              {
                   temp = a[j];
                   a[j] = a[j+1];
                   a[j+1] = temp;
              }
          }
     }

     return a;
}
