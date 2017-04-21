#include <stdio.h>

#define COLOR_BLACK     "\033[30m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_RED       "\033[31m"
#define COLOR_PURPLE    "\033[35m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_SKYBLUE   "\033[36m"

#define COLOR_YELLOW   "\033[33m"
#define COLOR_BLACK2     "\033[47;30m"

int main()
{
    char *buf = "test";
    printf( "%s[ERROR]%s\033[m\n", COLOR_RED, buf );
    printf( "%s[WARNING]%s\033[m\n", COLOR_GREEN, buf );
    printf( "[ALWAYS]%s\n", buf );

    printf( "%s[COLOR_BLACK]%s\033[m\n", COLOR_BLACK, buf );
    printf( "%s[COLOR_PURPLE]%s\033[m\n", COLOR_PURPLE, buf );
    printf( "%s[COLOR_BLUE]%s\033[m\n", COLOR_BLUE, buf );
    printf( "%s[COLOR_SKYBLUE]%s\033[m\n", COLOR_SKYBLUE, buf );

    printf( "%s[COLOR_YELLOW]%s\033[m\n", COLOR_YELLOW, buf );
    printf( "%s[COLOR_BLACK2]%s\033[m\n", COLOR_BLACK2, buf );

    return 0;
}
