// Secrets of "printf", see https://www.cypress.com/file/54441/download

#include <stdio.h>

int main()
{
    int n = 2;
    printf("%*c|\n", n, ' '); // The number of spaces, n, is greater than zero.
    printf("%*s|\n", n, " "); // The number of spaces, n, is greater than or equal to zero.

    int i;
    for (i = 1; i <= 31; i += 5)
        printf("%3d   ", i);
    printf("\n");
    for (i = 1; i <= 31; i += 5)
        printf("  |   ");
    printf("\n");

    /*
    printf("%*s1%*s2%*s3\n", 2, "",  5, "", 5, "");

    char *str = "Hello,";
    char *str2 = "world.";
    int leading = 2, trailing = 1;
    printf ( "%*c%s%*c%s\n", leading, ' ', str, trailing, ' ', str2);
    */

    return 0;
}
