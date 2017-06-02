#include <stdio.h>
#include "demo.h"

int main()
{
    extern int iii;
    printf("iii = %d\n", iii);

    init();
    printf("iii = %d\n", iii);
    return 0;
}
