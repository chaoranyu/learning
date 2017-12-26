#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Running ps with system\n");
    //ps进程结束后才返回，才能继续执行下面的代码
    system("ps au");// 1
    //system("ps au &");// 1
    printf("ps Done\n");
    exit(0);
}
