#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    int stat = 0;
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
            pid = wait(&stat);
            printf("Child has finished: PID = %d\n", pid);
            //检查子进程的退出状态
            if(WIFEXITED(stat))
                printf("Child exited with code %d\n", WEXITSTATUS(stat));
            else
                printf("Child terminated abnormallly\n");
            printf("Parent, ps Done\n");
            //printf("Parent: PID = %d\n", getpid());
            break;
    }
    exit(0);
}
