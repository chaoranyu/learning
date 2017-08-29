#include <stdio.h>  
#include <unistd.h>  

int main(void)  
{  
    if(access("dd", R_OK)==0)  printf("READ OK\n");  
    if(access("dd", W_OK)==0)  printf("WRITE OK\n");  
    if(access("dd", X_OK)==0)  printf("EXEC OK\n");  
    if(access("dd", F_OK)==0)  printf("DIR exist\n");  

    //if(access("dd", F_OK | R_OK | W_OK | X_OK)==0)
    //    printf("all OK\n");  
    //else
    //    printf("some ERR\n");
} 
