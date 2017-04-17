#include <stdio.h>

#define CLIENT  0x01
#define SERVER  0x02
//#define CLIENT  00000001
//#define SERVER  00000010

int main()
{
    char c = CLIENT | SERVER;

    printf("%d\n", c);
}
