/* gcc -o example example.c -lhiredis -fPIC -O3 */

#include <stdio.h>
#include <stdlib.h>

#include <hiredis/hiredis.h>

int main(int argc, char **argv)
{
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

    /* PING server */
    reply = redisCommand(c, "ping");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

    /* SET a key */
    reply = redisCommand(c, "SET %s %s", "foo", "hello world");
    printf("SET: %s\n", reply->str);
    freeReplyObject(reply);

    /* SET a key using binary safe API */
    reply = redisCommand(c, "SET %b %b", "bar", (size_t) 3, "kitty", (size_t) 5);
    printf("SET (binary API): %s\n", reply->str);
    freeReplyObject(reply);

    /* Try a GET and two INCR */
    reply = redisCommand(c, "GET %s", "foo");
    printf("GET: %s\n", reply->str);
    freeReplyObject(reply);

    reply = redisCommand(c, "INCR counter");
    printf("INCR: %lld\n", reply->integer);
    freeReplyObject(reply);
    /* again ... */
    reply = redisCommand(c, "INCR counter");
    printf("INCR: %lld\n", reply->integer);
    freeReplyObject(reply);

    /* Create a list of numbers, from 0 to 9 */

    /* Disconnects and free the context */
    redisFree(c);

    return 0;
}
