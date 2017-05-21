#include <stdio.h>

#define PRIME_10M   10000019

unsigned hash(unsigned key)
{
    return key % PRIME_10M;
}

unsigned hash2(unsigned key)
{
    return key & PRIME_10M;
}

main()
{
    unsigned a = 0x11223344;
    printf("0x%x\t0x%x\n", a, hash(a));
    unsigned b = 0x112233FF;
    printf("0x%x\t0x%x\n", b, hash(b));
    unsigned c = 0x04455666;
    printf("0x%x\t0x%x\n", c, hash(c));
    unsigned d = 0x00223344;
    printf("0x%x\t0x%x\n", d, hash(d));
    
//    printf("0x%x\t0x%x\n", a, hash2(a));
//    printf("0x%x\t0x%x\n", b, hash2(b));
//    printf("0x%x\t0x%x\n", c, hash2(c));
//    printf("0x%x\t0x%x\n", d, hash2(d));
}
