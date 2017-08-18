#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


static int * g_count = NULL;


__attribute__((constructor)) void load_file()
{
    printf("Constructor is called.\n");
    g_count = (int *)malloc(sizeof(int));
    if (g_count == NULL)
    {
        fprintf(stderr, "Failed to malloc memory.\n");
    }
}


__attribute__((destructor)) void unload_file()
{
    printf("Destructor is called.\n");
    if (g_count)
        free(g_count);
}


void func1()
{
    printf("SIGINT \n");
    //abort();
    exit(0);
}

void func2()
{
    printf("SIGTERM \n");
    unload_file();
    abort();
}

int main()
{
    signal(SIGINT, func1);
    signal(SIGTERM, func2);
    while(1);
    return 0;
}
