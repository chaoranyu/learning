#include <stdio.h>
#include <inttypes.h>
// #include <stdint.h>

int main(void)
{
    uint64_t foo = 10;
    printf("foo is equal to %" PRIu64 "!\n", foo);
    printf("foo is equal to %llu!\n", foo);

    printf("%s\n", PRIu64);

    return 0;
}
