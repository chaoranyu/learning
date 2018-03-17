#include <stdio.h>
#include <string.h>

#define uk "abcdefghijklmnopqrstuvwxyz0123456789"

int main()
{
    /* Test 1 */
    char src[32] = "hello";
    char dest[32] = "are you OK";

    char *s = strncpy(dest, src, sizeof(src));
    printf("src: %p, dest: %p, s: %p\n", src, dest, s);
    printf("src: %s, dest: %s\n", src, dest);

    /* Test 2 */
    char buffer[32];

    strncpy(buffer, uk, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';
    printf("buffer: %p\n", buffer);
    printf("buffer: %s\n", buffer);

    return 0;
}
