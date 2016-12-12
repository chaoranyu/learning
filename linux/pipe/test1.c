#include "stdio.h"
#include "unistd.h"

int main() {
        pid_t child_b, child_c;
        int pipefds[2]; //[0] for read, [1] for write
        char * arg1[] = {"/usr/bin/wc", NULL};
        char * arg2[] = {"/bin/ls", "-l", NULL};

        //父进程
        pipe(pipefds); // 开始创建管道的2段

        if(!(child_b = fork())) { //创建子进程b
                close(pipefds[1]); /* 关掉管道的读取端*/
                close(0); //关掉b进程的标准输入文件，其实就是键盘
                dup2(pipefds[0], 0); //将我们管道的输出段复制到 b进程的标准输入中
                close(pipefds[0]); //关掉输出
                execve("/usr/bin/wc", arg1, NULL); //执行wc进程
                printf("pid is %d, wc\n", getpid()); //只有出错才会到这里
        }
        close(pipefds[0]); /*close read*/

        if(!(child_c = fork())) { //创建子进程c
                close(1); //和上面雷同
                dup2(pipefds[1], 1);
                close(pipefds[1]);
                execve("/bin/ls", arg2, NULL);
                printf("pid is %d, ls\n", getpid());
        }

        close(pipefds[1]);
        wait4(child_b, NULL, 0, NULL);
        return 0;
}

