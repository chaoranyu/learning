#include <stdio.h>
#include <string.h>

int main()
{
    int offset = 0;
    //char *view_name = "sysname";
    //char *print_str; 
    char print_str[64]; 
    char test_str[64] = {"hello"}; 

    offset = snprintf(print_str, 64, ">>>>>>>>>> testing <<<<<<<<<");
    printf("offset = %d\n", offset);
    printf("%s\n\n", print_str);

    offset = snprintf(print_str + offset, 64, test_str);
    printf("offset = %d\n", offset);
    printf("%s\n\n", print_str);

    return 0;
}
