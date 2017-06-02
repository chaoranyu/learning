#include <stdio.h>
#include <stdlib.h>

#define fileout (fp1)
#define fileerr (fp2)

int main()
{
    FILE *fp1 = fopen("tcp-ddos.log", "w+");
    FILE *fp2 = fopen("tcp-ddos-err.log", "w+");

    fprintf(fileout, "hello world\n");
    fprintf(fileerr, "there is a bug!\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
