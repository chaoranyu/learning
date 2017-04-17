#include "stdio.h"
#include "stdint.h"

typedef struct TEST {
    int a;
    int b;
    char c;
} TEST_ST;

uint16_t ip_hash_to_index(uint32_t server_ip)
{
//#define ADDR_OFFSET 8

	uint16_t index;
	uint8_t h,h1,h2,h3;

	h1 = server_ip >> 24;
	h2 = (server_ip >> 16)  & 0xFF;
	h3 = (server_ip >> 8) & 0xFF;
	
	h = h1 ^ h2 ^ h3;
	
	index = ( h << 8) | (server_ip & 0xFF);
	return index;
}

main() {
    TEST_ST *t = (TEST_ST *)malloc(sizeof(TEST_ST));
    printf("%p  %p\n", t, t+1);

    int ip = 0x7f1a2511;
    printf("0x%x  0x%x\n", ip, ip_hash_to_index(ip));
}
