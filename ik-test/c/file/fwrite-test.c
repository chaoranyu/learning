#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum { SIZE = 5 };

int main(void)
{
    char buffer[128];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "hello\n");

    FILE *f1 = fopen("file.bin", "wb");
    assert(f1);
    int r1 = fwrite(buffer, 1, sizeof(buffer), f1);
    printf("wrote %d elements\n", r1);
    fclose(f1);
    //
    //double a[SIZE] = {1, 2, 3, 4, 5};
    //FILE *f1 = fopen("file.bin", "wb");
    //assert(f1);
    //int r1 = fwrite(a, sizeof a[0], SIZE, f1);
    //printf("wrote %d elements out of %d requested\n", r1,  SIZE);
    //fclose(f1);
 
    //double b[SIZE];
    //FILE *f2 = fopen("file.bin", "rb");
    //int r2 = fread(b, sizeof b[0], SIZE, f2);
    //fclose(f2);
    //printf("read back: ");
    //for(int i = 0; i < r2; i++)
    //    printf("%f ", b[i]);

    return 0;
}
