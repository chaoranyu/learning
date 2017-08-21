#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{ 
    struct stat buf;
    memset(&buf, 0, sizeof(struct stat));
    stat("/etc/hello", &buf);
    printf("/etc/hello, %d\n", S_ISDIR(buf.st_mode));

    return 0;
} 
