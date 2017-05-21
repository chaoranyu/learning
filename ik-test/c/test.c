#include <stdio.h>
#include <stdint.h>
//#include <stdlib.h>
#include <string.h>

typedef struct {
   uint64_t ip   : 32; 
   uint64_t port : 16; 
   uint64_t ttl  : 8; 
} TEST_A;

typedef struct {
   uint32_t ip; 
   uint16_t port; 
   uint8_t ttl; 
} TEST_B;

#define TEST_NUM    500000000

void test1();
void test2();

int main()
{
    test1();
    test2();

    return 0;
}

void test1()
{
    TEST_A a = {0x10101010, 0x20, 64};
    TEST_A b = {0x10101010, 0x20, 64};

    for (int i = 0; i < TEST_NUM; i++)
        memcmp(&a, &b, 4);
        //(uint64_t)a == (uint64_t)b;
}

void test2()
{
    TEST_B a = {0x10101010, 0x20, 64};
    TEST_B b = {0x10101010, 0x20, 64};

    for (int i = 0; i < TEST_NUM; i++)
    {
        a.ip == b.ip;
        a.port == b.port;
        a.ttl == b.ttl;
    }
}
