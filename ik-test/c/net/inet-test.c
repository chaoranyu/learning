#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct in_addr addr1,addr2;
    ulong l1;
    l1= inet_addr("10.0.4.100");
    printf("l1: %u\n", l1);
    memcpy(&addr1, &l1, 4);
    printf("addr1: %s\n", inet_ntoa(addr1)); //注意这一句的运行结果
    return 0;
}
