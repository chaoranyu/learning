#include <stdio.h>

int
main()
{
    char *s = "]\x80\xfa\xd2\xb9\xcd\xb8\x92\x16\x04\\V\xb2\x11\xe1\x9c\x8d\xb0\xc3\x12\xc1\xee\x88\xe2\xf4\xb1\x070\n&\xed\xccN\xd5\x91\x9b\xfe\xf0ku\xa7\\cz\x84\x8f\x04";
    printf("%s\n\n", s);

    unsigned char ch;
    while ((ch = *s++) != 0)
    {
        printf("%u  ", ch);
    }
    printf("\n");

    return 0;
}
