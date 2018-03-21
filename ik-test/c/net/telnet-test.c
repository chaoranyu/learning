#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#define HOST_IP "127.0.0.1"
#define PORT_NUM 13         /* daytime port number */
#define BUF_SIZE 1024
 
int main()
{
    /* Fill in required details in the socket structure */
    struct sockaddr_in remote;
    memset(&remote, 0, sizeof(remote));
    remote.sin_family = AF_INET;
    remote.sin_port = htons(PORT_NUM);
    remote.sin_addr.s_addr = inet_addr(HOST_IP);
 
    if (remote.sin_addr.s_addr == INADDR_NONE)
    {
        perror("inet_addr");
        return -1;
    }
 
    /* Create a socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        return -1;
    }
 
    /* Connect to remote host */
    if(connect(sock, (struct sockaddr *) &remote, sizeof(remote)) < 0)
    {
        perror("connect");
        close(sock);
        return -1;
    }
 
    /* Read the data */
    char buffer[BUF_SIZE + 1];
    ssize_t tot = 0;
    for (;;)
    {
        ssize_t cur = read(sock, buffer + tot, BUF_SIZE - tot);
        if (cur < 0)
        {
            if (errno != EINTR)
            {
                perror("read");
                close(sock);
                return -1;
            }
            else
            {
                /* No data was read, interrupted */
                continue;
            }
        }
        else if (!cur)
        {
            break;
        }
        else
        {
            tot += cur;
        }
    }
    /* Just to prevent overflow while printing */
    buffer[BUF_SIZE] = '\0';
 
    /* Print the date on the screen */
    printf("%s", buffer);
 
    return 0;
}

int sendall(int s, char *buf, int *len)
{
    int total = 0; // 我们已经送出多少 bytes 的数据
    int bytesleft = *len; // 我们还有多少数据要送
    int n;

    while(total < *len) {
        n = send(s, buf+total, bytesleft, 0);
        if (n == -1) { break; }
        total += n;
        bytesleft -= n;
    }

    *len = total; // 返回实际上送出的数据量

    return n==-1?-1:0; // 失败时返回 -1丶成功时返回 0
}


