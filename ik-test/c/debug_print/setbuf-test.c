#include <stdio.h>
//#include <threads.h>
#include <sys/time.h>
#include <sys/select.h>

int main(void)
{
    struct timeval tv;
    //setbuf(NULL, NULL); // segmentation fault
    setbuf(stdout, NULL); // unbuffered stdout
    putchar('a'); // 'a' appears immediately if stdout is unbuffered

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    select(0, NULL, NULL, NULL, &tv);
    //thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); // sleep 1 sec
    putchar('b'); 
    putchar('\n');
}
