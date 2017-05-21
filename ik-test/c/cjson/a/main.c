#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char info[]=STR_INFO;      // 这里的宏定义来自Makefile
const char date[]=STR_DATE;      // 这里的宏定义来自Makefile

int main(void)
{
    printf("%s\n", info);
    printf("%s\n", date);

    return 0;
}
