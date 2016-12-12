#include <stdio.h>
#include "limits.h"

void main()
{
    printf("signed char:%ld--%ld\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:%ld--%ld\n", 0, UCHAR_MAX);
    printf("signed short:%ld--%ld\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:%ld--%ld\n", 0, USHRT_MAX);
    printf("signed int:%ld--%ld\n", INT_MIN, INT_MAX);
    printf("unsigned int:%ld--%u\n", 0, UINT_MAX);
    printf("signed long:%ld--%ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:%ld--%u\n", 0, ULONG_MAX);
}
