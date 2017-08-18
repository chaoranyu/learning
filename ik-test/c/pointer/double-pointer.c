#include <stdio.h>

int main()
{
    int a[2][3] = { {1, 2, 3}, {4, 5, 6} };

    printf("%p\n", *(a + 1));

    return 0;
}
