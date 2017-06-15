#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{ 
    struct stat buf;
    stat("/etc/passwd", &buf);
    printf("/etc/passwd file size = %lld\n", buf.st_size);

    return 0;
} 
