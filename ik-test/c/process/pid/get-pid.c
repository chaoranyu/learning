#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define WORKER_PROGRAM  "gunicorn: worker \\[test]"
//#define SIG_TO_TEST             (__SIGRTMIN + 14)   /* 46 */
#define SIG_TO_TEST             SIGKILL   /* 9 */
#define COMMON_LEN              (256U)

int get_pid_of_worker(int* pid);

int
main()
{
    pid_t pid;
    int sig;
    int result;

    result = get_pid_of_worker(&pid);    
    if (result != 0)
    {
        fprintf(stderr, "Cannot find worker process.\n");
        return 1;
    }

    sig = SIGKILL;
    result = kill(pid, sig);
    if (result != 0)
    {
        fprintf(stderr, "kill(%d, %d) failed.\n", pid, sig);
        return 2;
    }

    fprintf(stdout, "kill(%d, %d) success.\n", pid, sig);

    return 0;
}

int
get_pid_of_worker(int* pid)
{
    FILE *fp = NULL;
    char cmd[COMMON_LEN] = "ps -ef | egrep '" WORKER_PROGRAM "' | "
                           "grep -v grep | tr -s ' ' | cut -f2 -d' '";

    fp = popen(cmd, "r");
    if(!fp)
    {
        fprintf(stderr, "popen error(%s).\n", cmd);
        return -1;
    }

    int count = 0;
    char buf[COMMON_LEN] = { 0 };
    while ((fgets(buf, sizeof(buf), fp))!= NULL)
    {
        if (count < 1)
        {
            int len = strlen(buf);
            if (len > 0 && buf[len-1] == '\n')
                buf[len-1] = '\0';

            *pid = atoi(buf);
        }

        count++;
    }

    if (count == 0)
        return -1;

    fprintf(stdout, "pid = %d (count = %u)\n", *pid, count);

    return 0;
}
