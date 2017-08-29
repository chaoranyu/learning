#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{ 
    struct stat buf;
    memset(&buf, 0, sizeof(struct stat));

    stat("/etc/passwd", &buf);
    //printf("/etc/passwd file size = %lld\n", buf.st_size);
    printf("/etc/passwd file size = %zu\n", buf.st_size);

    memset(&buf, 0, sizeof(struct stat));
    stat("/etc/hello", &buf);
    //printf("/etc/hello file size = %lld\n", buf.st_size);
    printf("/etc/hello file size = %zu\n", buf.st_size);

    return 0;
} 
