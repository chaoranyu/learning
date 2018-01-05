#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>


#define PCAP_STORE_PATH_1        "/home/pcap1/"
#define PCAP_STORE_PATH_2        "/home/pcap2"

void my_mkdirs(const char *muldir);
int test(char *path);

int
main()
{
    /* cd /home; touch pcap1 */
    test(PCAP_STORE_PATH_1);
    /* cd /home; touch pcap2 */
    test(PCAP_STORE_PATH_2);

    return 0;
}


void
my_mkdirs(const char *muldir)
{
    int i,len;
    char str[1024];
    strncpy(str, muldir, 1024);

    len=strlen(str);
    for (i = 0; i < len; i++)
    {
        if( str[i]=='/' )
        {
            str[i] = '\0';
            if(access(str,0)!=0)
            {
                mkdir(str, 0775);
            }
            str[i] = '/';
        }
    }

    if (len > 0 && access(str,0) != 0)
    {
        mkdir(str, 0775);
    }

    return;
}

int
test(char *path)
{
    struct stat stat_info;
    char handle_path[1024] = { 0 };
    char *tmp = handle_path;

    strncpy(handle_path, path, 1024);

    if(access(handle_path, F_OK) == 0)
    {
        /* If it's not a directory, remove it and create directory */
        memset(&stat_info, 0, sizeof(struct stat));
        stat(handle_path, &stat_info);
        if(!S_ISDIR(stat_info.st_mode))
        {
            fprintf(stdout, "%s is not dir.\n", handle_path);
            if(remove(handle_path) == 0)
            {
                fprintf(stdout, "remove file and mkdir.\n");
                my_mkdirs(handle_path);
            }
            else
            {
                fprintf(stderr, "remove file %s failed.\n", handle_path);
                return -1;
            }
        }
        else
        {
            fprintf(stdout, "%s is dir.\n", handle_path);
        }

        /* Change file mode bits */
        if(access(handle_path, R_OK | W_OK | X_OK) == 0)
        {
            chmod(handle_path, S_IRUSR | S_IWUSR | S_IXUSR);
        }
    }
    else
    {
        /* If the directory not exsit, make it recursively */
        fprintf(stdout, "Dir %s not exists, errno = %d.\n", handle_path, errno);
        switch (errno)
        {
        case ENOTDIR:
            while (*tmp++ != '\0');
            *(tmp - 2) = '\0';

            if(remove(handle_path) == 0)
            {
                fprintf(stdout, "remove file and mkdir.\n");
                my_mkdirs(handle_path);
            }
            else
            {
                fprintf(stderr, "remove file %s failed.\n", handle_path);
                return -1;
            }
            break;

        default:
            break;
        }

        my_mkdirs(handle_path);
    }

    fprintf(stdout, "Dir %s exists now.\n", handle_path);

    return 0;
}
