#include <stdio.h>
#include <string.h>

int main()
{
    int tmp = 1000;
    char str[22]; //char str[20];
    int size = sizeof(str);
    int n = snprintf(str, size, "%d * %d = %d", tmp, tmp, tmp*tmp);
    if (n >= size || n < 0)
    {
        printf("warning, len = %d!\n", n);
        // str[size-1] = '\0'; // not necessary
    }

    printf("%s [len=%d]\n", str, n);

    return 0;
}
