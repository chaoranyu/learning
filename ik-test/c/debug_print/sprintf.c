#include <stdio.h>
#include <string.h>

int main()
{
    char *view_name = "sysname";
    //char *print_str; 
    char print_str[64]; 
    sprintf((print_str), "\n >>>>>>>>>> testing <<<<<<<<<\n");
 //   sprintf((print_str), "\n >>>>>>>>>> testing <<<<<<<<<%s\n", "ss");
    printf("%s\n", print_str);
    sprintf((print_str), "\n view para error!view :%s\n", view_name);

    printf("%s\n", print_str);

    return 0;
}
