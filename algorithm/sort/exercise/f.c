#include <stdio.h>

float sort(int data[], int num);

void main()
{
    int a[10] = {3, 5, 1 ,9, 6, 4, 2, 8, 7, 10};
    int d = sort(a, 10);

    for (int i = 0; i < 10 ; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
    printf("%d\n", d);

    int b = 0xFFFFFFFF;
    char c = b;
    printf("%d\n", c);
    float f = 3.1415F;
    //double g = f;
    double g = (double)f;
    printf("%lf\n", g);
}

float sort(int a[], int num)
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
     return (int)1;
}
