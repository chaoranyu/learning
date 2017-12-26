#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Running ps with execlp\n");
    execlp("ps", "ps", "au", (char*)0);
    printf("ps Done");
    exit(0);
}
