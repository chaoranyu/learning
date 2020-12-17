#include <stdio.h>
#include <stdint.h>

int main()
{
    union {
        uint32_t addr;
        struct {
            uint32_t addr_prefix: 24;
            uint32_t addr_host: 8;
        };
    } ip;

    ip.addr = 0x04030201;

    printf("ip1: addr = 0x%x, addr_prefix = 0x%x, addr_host = 0x%x\n",
            ip.addr, ip.addr_prefix, ip.addr_host);

    union {
        uint32_t addr;
        struct {
            uint32_t prefix: 24;
            uint32_t host: 8;
        } addr2;
        // uint32_t prefex. // Error: duplicate member
    } ip2;

    ip2.addr = 0x04030201;

    printf("ip2: addr = 0x%x, addr_prefix = 0x%x, addr_host = 0x%x\n",
            ip2.addr, ip2.addr2.prefix, ip2.addr2.host);
            //ip2.addr, ip2.prefix, ip2.host);

    return 0;
}
