#include <stdio.h>

#pragma pack(8)
struct D{
    char  b;
    short a;
    char  c;
};
#pragma pack()

int main()
{
    struct D d[100];
    printf("sizeof(D) = %ld\n", sizeof(struct D));
    printf("sizeof(d) = %ld\n", sizeof(d));

    return 0;
}
