/* gcc -o readredis readredis.c -lhiredis -fPIC -O3 */

#include <stdio.h>
#include <stdlib.h>

#include <hiredis/hiredis.h>

void print_hex(const unsigned char *s, size_t len);

int main(int argc, char **argv)
{
    unsigned int j;
    redisContext *c;
    redisReply *reply;
    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = (argc > 2) ? atoi(argv[2]) : 6379;

    const struct timeval tv = { 1, 500000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, tv);
    if (c == NULL || c->err)
    {
        if (c)
        {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        }
        else
        {
            printf("Connection error: can't allocate redis context\n");
        }
    
        exit(1);
    }

    /* Try a GET and two INCR */
    int i = 0;
    for (i = 0; i < 100; ++i)
    {
        reply = redisCommand(c, "GET %s", "app_flow_1");
        printf("\n-------  %02d ------\nGET APP: \n", i+1);
        print_hex(reply->str, reply->len);
        printf("    [%u]\n", reply->len);
        //printf("GET: %d  %lld  %ld  %ld\n", reply->type, reply->integer, reply->len, reply->elements);
        freeReplyObject(reply);

        printf("\nLRANGE interface: \n");
        reply = redisCommand(c, "LRANGE interface_flow_1 0 -1");
        if (reply->type == REDIS_REPLY_ARRAY)
        {
            for (j = 0; j < reply->elements; j++)
            {
                printf("%u) ", j);
                print_hex(reply->element[j]->str, reply->element[j]->len);
                printf("    [%u]\n", reply->element[j]->len);
            }
        }
        freeReplyObject(reply);

        printf("\nLRANGE signip: \n");
        reply = redisCommand(c, "LRANGE signip_inflow_1_1 0 -1");
        if (reply->type == REDIS_REPLY_ARRAY)
        {
            for (j = 0; j < reply->elements; j++)
            {
                printf("%u) ", j);
                print_hex(reply->element[j]->str, reply->element[j]->len);
                printf("    [%u]\n", reply->element[j]->len);
            }
        }
        freeReplyObject(reply);

        sleep(1);
    }

    /* Disconnects and free the context */
    redisFree(c);

    return 0;
}

void print_hex(const unsigned char *s, size_t len)
{
    if (s == NULL)
    {
        printf("null");
        return;
    }

    unsigned char c;
	size_t i = 0;
    while((c = *(s+i)) != '\0' || i < len)
	{
        printf("0x%02x ", c);
		i++;
	}

    return;
}
