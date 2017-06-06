#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>// comment this line, there is a warning

uint16_t ip_hash_to_index(uint32_t h)
{
    //#define ADDR_OFFSET 8

    h ^= (h >> 20) ^ (h >> 12);
    return h ^ (h >> 7) ^ (h >> 4);
}

main() {
    int ip = 0x7f1a2511;
    printf("0x%x  0x%x\n", ip, ip_hash_to_index(ip));
    ip = 0x0a000201;
    printf("0x%x  0x%x\n", ip, ip_hash_to_index(ip));
}
