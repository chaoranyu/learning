/**
 * @FileName    chk_signal_exist.c
 * @Describe    A simple example for checking if a proccess is existing in linux.
 * @Author      vfhky 2016-03-14 11:48 https://typecodes.com/cseries/kill0checkprocessifexist.html
 * @Compile     gcc chk_signal_exist.c -o chk_signal_exist
 */

#include <stdio.h>
#include <signal.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define GO_FREE(p) \
    free(p);    \
    p = NULL;   \
    printf( "exit.\n" );

int main( int argc, char **argv )
{
    if( argc != 2 )
    {
        printf( "Usage: %s %s\n", argv[0], "pid" );
        exit(-1);
    }
    if( strlen(argv[1]) >= 10 )
    {
        printf( "Invalid pid: %s\n", argv[1] );
        exit(-1);
    }
    char *p = (char *)malloc( sizeof(char) * 20 );
    memcpy( p, argv[1], strlen(argv[1]) );
    //memcpy( p, argv[1], 20 );

    /**
     * no signal is sent, but error checking is still performed;
     * this can be used to check for the existence of a process ID or process group ID.
     */
    if( kill( atoi(p), 0 ) == -1 )
    {
        perror( "error" );
    }
    else
    {
        printf( "Signal[%s] exist.\n", p );
    }
    GO_FREE(p);
    return 0;
}
