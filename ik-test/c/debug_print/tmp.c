#include <stdio.h>
#include <string.h>

int main()
{
    int offset = 0, len = 0;
    char print_str[64] = {0}; 
    char test_str[64] = {"hello"}; 

    offset += len = snprintf(print_str, 64, test_str);
    printf("len = %d, offset = %u\n", len, offset);
    printf("%s\n\n", print_str);

    while (len++ <= 10)
        offset += snprintf(print_str + offset, 64, " ");
    offset += snprintf(print_str + offset, 64, test_str);
    printf("offset = %d\n", offset);
    printf("%s\n\n", print_str);

    return 0;
}
