#include <stdio.h>
#include <stdint.h>

typedef struct ip_str {
    char h0;
    char h1;
    char h2;
    char h3;
} ip_str_t;

typedef union ip_store{
    uint32_t num;
    ip_str_t str;
} ip_store_t;

int main()
{
    ip_store_t ip_data;
    ip_data.num = 0x12121233;

    printf("ip = 0x%x, ip = %u.%u.%u.%u\n", ip_data.num, ip_data.str.h3, ip_data.str.h2, ip_data.str.h1, ip_data.str.h0);

}
