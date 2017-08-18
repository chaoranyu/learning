#include <stdio.h>

int get_number(int flag)
{
    if (flag)
    {
        static int i = 0;
        i++;
        return i;
    }
    else
    {
        static int i = 0;
        i += 5;
        return i;
    }
}

int main()
{
    printf("%d\n", get_number(1));
    printf("%d\n", get_number(0));
    printf("%d\n", get_number(1));
    printf("%d\n", get_number(0));

    return 0;
}
