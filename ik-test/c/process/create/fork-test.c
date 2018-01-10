#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    switch(pid)
    {
        case -1:
            perror("fork failed");
            exit(1);
            break;
        case 0:
            //这是在子进程中，调用execlp切换为ps进程
            printf("\n");
            execlp("ps", "ps", "au", 0);
            break;
        default:
            //这是在父进程中，输出相关提示信息
            printf("Parent, ps Done\n");
            break;
    }
    exit(0);
}
