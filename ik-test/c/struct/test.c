#include <stdio.h>  

struct mych {  
    int k;  
};  

struct myst {  
    int         i;    
    int         j;    
    struct mych ch;   
};  

int main(void)   
{
    struct myst st = { 1 ,2, {4}};
    //struct myst st = {   
    //    .i = 1,  
    //    .j = 2,  
    //    .ch = {   
    //        .k = 3   
    //    }     
    //};    
    printf("st.i = %d, st.j = %d, st.ch.k = %d\n", st.i, st.j, st.ch.k);  
    return 0;  
}
