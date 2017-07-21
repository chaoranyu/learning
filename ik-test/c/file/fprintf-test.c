#include <stdio.h>
#include <string.h>

int main()
{ 
    FILE * pFile;
    pFile = fopen ("myfile.txt","w");

    if (pFile == NULL)
    {
        printf("Open myfile.txt error!\n");
        return 1;
    }

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "hello\n");
    fprintf(pFile, "%s", buf); 

    memset(buf, 0, sizeof(buf));
    strcpy(buf, "world\n");
    fprintf(pFile, "%s", buf); 

    fclose (pFile);

    return 0;
}
