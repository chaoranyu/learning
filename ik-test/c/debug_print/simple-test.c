#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define COLOR_BLACK     "\033[30m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_RED       "\033[31m"
#define COLOR_PURPLE    "\033[35m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_SKYBLUE   "\033[36m"

#define DD_CONFIG_DEBUG_PRINT

#ifdef DD_CONFIG_DEBUG_PRINT
#define DDDP_ERROR( arg ) do {              \
        PrintError arg ;     \
    } while(0)

#define DDDP_WARNING( arg ) do {            \
        PrintWarning arg ;   \
    } while(0)

#define DDDP_ALWAYS( arg )  do {              \
        Print arg ;   \
    } while(0)

#define DDDP_INTERNAL( arg ) do {               \
        PrintInternal arg;   \
    } while ( 0 )

#define DDDP( flag, arg ) do {            \
        if ( GetDPFlag() & flag ) {       \
            Print("[DD]"); \
            Print arg ;    \
        }                                 \
    } while ( 0 )
#else  // !DD_CONFIG_DEBUG_PRINT
#define DDDP_ERROR( arg )    do { } while ( 0 )
#define DDDP_WARNING( arg )  do { } while ( 0 )
#define DDDP_ALWAYS( arg )   do { } while ( 0 )
#define DDDP( flag, arg )    do { } while ( 0 )
#define DDDP_INTERNAL( arg ) do { } while ( 0 )
#endif // DD_CONFIG_DEBUG_PRINT

#define BUFSIZE 120
int m_enable_error = 1;
int m_enable_warning = 1;
int m_enable_output = 1;

#if 1
int
IsIkosAvailable()
{
    return 0;
}

int
IkosInterErrLog()
{
    return 0;
}

int
IkosInterWarningLog()
{
    return 0;
}

int
IkosInternalLog()
{
    return 0;
}

int
IkosDebugLog()
{
    return 0;
}

#endif

int
PrintError( const char* fmt, ... )
{
    char buf[BUFSIZE];
    va_list ap;
    int ret;

    va_start( ap, fmt );
    ret = vsnprintf( buf, sizeof(buf), fmt, ap );
    va_end( ap );

    if ( !m_enable_error ) {
        return ret;
    }

    int len = strlen( buf );
    if ( 1 <= len && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }

    if ( IsIkosAvailable() ) {
        IkosInterErrLog(( "%s[ERROR]%s\033[m\n", COLOR_RED, buf ));
    } else {
        printf( "%s[ERROR]%s\033[m\n", COLOR_RED, buf );
    }

    return ret;
}

int
PrintWarning( const char* fmt, ... )
{
    char buf[BUFSIZE];
    va_list ap;
    int ret;

    va_start( ap, fmt );
    ret = vsnprintf( buf, sizeof(buf), fmt, ap );
    va_end( ap );

    if ( !m_enable_warning ) {
        return ret;
    }

    int len = strlen( buf );
    if ( 1 <= len && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }

    if ( IsIkosAvailable() ) {
        IkosInterWarningLog(( "%s[WARNING]%s\033[m\n", COLOR_GREEN, buf ));
    } else {
        printf( "%s[WARNING]%s\033[m\n", COLOR_GREEN, buf );
    }

    return ret;
}

int
PrintInternal( const char* fmt, ... )
{
    char buf[BUFSIZE];
    va_list ap;
    int ret;

    va_start( ap, fmt );
    ret = vsnprintf( buf, sizeof(buf), fmt, ap );
    va_end( ap );

    if ( !m_enable_warning ) {
        return ret;
    }

    int len = strlen( buf );
    if ( 1 <= len && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }

    if ( IsIkosAvailable() ) {
        IkosInternalLog(( "%s\n", buf ));
    } else {
        printf( "%s\n", buf );
    }

    return ret;
}

int
Print( const char* fmt, ... )
{
    char buf[BUFSIZE];
    va_list ap;
    int ret;

    va_start( ap, fmt );
    ret = vsnprintf( buf, sizeof(buf), fmt, ap );
    va_end( ap );

    if ( !m_enable_output ) {
        return ret;
    }

    if ( IsIkosAvailable() ) {
        IkosDebugLog(( "%s", buf ));
    } else {
        printf( "%s", buf );
    }

    return ret;
}

int main()
{
    char *s = "test";

    DDDP_ERROR("test 1");
    DDDP_WARNING("test 2");
    DDDP_ALWAYS("test 3");
    //DDDP( flag, arg );
    DDDP_INTERNAL("test 5");

    return 0;
}
