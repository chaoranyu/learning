#include <stdio.h>
#define FILE_NAME_LEN 1024

void mkdirs(char *muldir)
{
    int i,len;
    char str[];
    strncpy(str, muldir, FILE_NAME_LEN);

    len=strlen(str);
    for (i = 0; i < len; i++)
    {
        if( str[i]=='/' )
        {
            str[i] = '\0';
            if(access(str,0)!=0)
            {
                mkdir(str, 0777);
            }
            str[i] = '/';
        }
    }

    if (len > 0 && access(str,0) != 0)
    {
        mkdir(str, 0777);
    }

    return;
}

int main()
{
    mkdirs("a/b/c/");
    mkdirs("a/b/d");

    return 0;
}
