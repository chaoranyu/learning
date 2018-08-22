#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

#define DIPT_NUM_LITTLE     5
#define DIPT_NUM            4000000

int test_correct(void);
int test_performance(void);

int main(int argc, char *argv[])
{
    printf("\n======= 1. Correctness test =======\n");
    test_correct();

    printf("\n======= 2. Performance test =======\n");
    test_performance();

    return 0;
}

int test_correct(void)
{
    char iplist[DIPT_NUM_LITTLE][16] = {0};
    struct in_addr addr1;
    unsigned int ui = 0;

    for (ui = 0; ui < DIPT_NUM_LITTLE; ui++)
    {
        memcpy(&addr1, &ui, 4);
        strcpy(iplist[ui], inet_ntoa(addr1));
    }

    unsigned ip;
    for (ui = 0; ui < DIPT_NUM_LITTLE; ui++)
    {
        ip = inet_addr(iplist[ui]);
        printf("[%02u] ip = 0x%x\n", ui, ip);
    }

    return 0;
}

int test_performance(void)
{
    typedef char (ipname_t)[16];
    struct in_addr addr1;
    unsigned int ui = 0;
    unsigned int random;

    ipname_t *iplist =
        (ipname_t *)malloc(sizeof(ipname_t) * DIPT_NUM);
    if (iplist == NULL)
    {
        printf("malloc of iplist failed.\n");
        return 1;
    }

    srand(time(NULL));

    time_t start, finish;
    start = time(NULL);
    for (ui = 0; ui < DIPT_NUM; ui++)
    {
        random = rand();
        memcpy(&addr1, &random, 4);
        strcpy(iplist[ui], inet_ntoa(addr1));
    }
    finish = time(NULL);

    printf("Cost %ds.\n", finish - start);

    unsigned *ip = (unsigned *)malloc(sizeof(unsigned) * DIPT_NUM);
    if (ip == NULL)
    {
        printf("malloc of ip failed.\n");
        return 1;
    }

    start = time(NULL);
    for (ui = 0; ui < DIPT_NUM; ui++)
    {
        ip[ui] = inet_addr(iplist[ui]);
    }
    finish = time(NULL);

    printf("Cost %ds.\n", finish - start);
    
    unsigned long long total = 0;
    for (ui = 0; ui < DIPT_NUM; ui++)
    {
        total += ip[ui];
    }
    printf("ip_num = %u, total = %llu\n\n", DIPT_NUM, total);

    free(iplist);
    free(ip);

    return 0;
}
