#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float f;
    char buffer[256];
    printf("Enter a number: ");
    fgets(buffer, 256, stdin);
    f = atof(buffer);
    printf("The value entered is %f\n", f);
    // system("pause");
    return 0;
}
