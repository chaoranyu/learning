#include <stdio.h>
#include <time.h>
#include <locale.h>
 
int main(void)
{
    char text[26];  // Try 25, interesting
    time_t now = time(NULL);
    //struct tm *t = localtime(&now);
    struct tm now_time;
    struct tm *t = localtime_r(&now, &now_time);

    if (NULL == t)
    {
        printf("localtime_r error\n");
        return -1;
    }

    strftime(text, sizeof(text)-1, "%y%m%d-%H%M%S", t);
    printf("file name: test-%s.log\n", text);

    strftime(text, sizeof(text)-1, "%c", t);
    printf("file name: test-%s.log\n", text);

    return 0;
}
