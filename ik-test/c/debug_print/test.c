#include <stdio.h>

#define COLOR_BLACK     "\033[30m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_RED       "\033[31m"
#define COLOR_PURPLE    "\033[35m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_SKYBLUE   "\033[36m"

#define COLOR_YELLOW   "\033[33m"

int main()
{
    char *buf = "test";
    printf( "%s[ERROR]%s\033[m\n", COLOR_RED, buf );
    printf( "%s[WARNING]%s\033[m\n", COLOR_GREEN, buf );
    printf( "%s\n", buf );

    printf( "%s[TEST]%s\033[m\n", COLOR_BLACK, buf );
    printf( "%s[TEST]%s\033[m\n", COLOR_PURPLE, buf );
    printf( "%s[TEST]%s\033[m\n", COLOR_BLUE, buf );
    printf( "%s[TEST]%s\033[m\n", COLOR_SKYBLUE, buf );

    printf( "%s[TEST]%s\033[m\n", COLOR_YELLOW, buf );

    return 0;
}
