#include <stdio.h>

int hammingWeight(unsigned int n) {
    int ret = 0;

    while(n != 0) {
        if(n & 0x1 != 0) {
            ret++;
        }
        n >>= 1;
    }

    return ret;
}

int main()
{
    unsigned int num = 0x7;
    printf("%d\n", hammingWeight(num));

    return 0;
}
