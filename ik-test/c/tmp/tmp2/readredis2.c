/* gcc -o readredis readredis.c -lhiredis -fPIC -O3 */

#include <stdio.h>
#include <stdlib.h>

#include <hiredis/hiredis.h>

void print_reply_hex(redisReply *reply);

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
        printf("\n-------  %02d  -------\nGET APP:\n", i+1);
        reply = redisCommand(c, "GET %s", "app_flow_1");
        print_reply_hex(reply);
        //printf("GET: %d  %lld  %ld  %ld\n", reply->type, reply->integer, reply->len, reply->elements);
        freeReplyObject(reply);

        printf("\nLRANGE interface:\n");
        reply = redisCommand(c, "LRANGE interface_flow_1 0 -1");
        print_reply_hex(reply);
        freeReplyObject(reply);

        printf("\nLRANGE signip 1:\n");
        reply = redisCommand(c, "LRANGE signip_inflow_1_1 0 -1");
        print_reply_hex(reply);
        freeReplyObject(reply);

        printf("\nLRANGE http signip 1:\n");
        reply = redisCommand(c, "LRANGE http_flow_byip_1 0 -1");
        print_reply_hex(reply);
        freeReplyObject(reply);

        sleep(1);
    }

    /* Disconnects and free the context */
    redisFree(c);

    return 0;
}

void print_reply_hex(redisReply *reply)
{
    redisReply *r = reply;
    size_t i, j, len;
    char *str;
    unsigned char c;

    if (r == NULL)
    {
        printf("Nullptr Exception.\n");
        return;
    }

    switch(r->type)
    {
    case REDIS_REPLY_INTEGER:
        printf("%d\n", reply->integer);
        break;

    case REDIS_REPLY_ARRAY:
        if (r->element != NULL)
        {
            printf("total: %d\n", r->elements);

            for (i = 0; i < r->elements; i++) 
            {
                if (r->element[i] != NULL)
                {
                    str = r->element[i]->str;
                    len = r->element[i]->len;

                    printf("%u)  ", i);

                    for (j = 0; j < len; j++)
                    {
                        //if (j % 16 == 0 && j != 0)
                        //    printf(" ");
                        if (j % 32 == 0 && j != 0)
                            printf("\n    ");

                        printf("%02x ", c = *(str+j));
                    }

                    //for (; j % 32 < 28; j++)
                    //    printf("   ");
                    printf("   [len = %u]\n", len);
                }
            }

            printf("\n");
        }    

        break;

    case REDIS_REPLY_ERROR:
    case REDIS_REPLY_STATUS:
    case REDIS_REPLY_STRING:
        if (r->str != NULL)
        {
            str = r->str;
            len = r->len;

            printf("    ");

            for (j = 0; j < len; j++)
            {
                if (j % 32 == 0 && j != 0)
                    printf("\n    ");

                printf("%02x ", c = *(str+j));
            }

            //for (; j % 32 < 28; j++)
            //    printf("   ");
            printf("   [len = %u]\n", len);
        }

        break;
    }    

    return;
}
