#define COLOR_GREEN     "\033[32m"
#define COLOR_RED       "\033[31m"
#define COLOR_PURPLE    "\033[35m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_SKYBLUE   "\033[36m"
#define COLOR_YELLOW    "\033[33m"

#ifdef DEBUG_DDOS_PRINT
#define DEBUG_LINE()    do {                                \
        fprintf(stdout, "[%s:%s] line=%d\n",                \
            __FILE__, __func__, __LINE__);                  \
    } while (0)

#define DEBUG_ERR(fmt, args...)     do {                    \
        fprintf(stderr, "%s[%s:%d] "fmt"\033[m\n",          \
            COLOR_RED, __func__, __LINE__, ##args);         \
    } while (0)

#define DEBUG_WARNING(fmt, args...) do {                    \
        fprintf(stdout, "%s[%s:%d] "fmt"\033[m\n",          \
            COLOR_GREEN, __func__, __LINE__, ##args);       \
    } while (0)

#define DEBUG_ALWAYS(fmt, args...)  do {                    \
        fprintf(stdout, "[%s:%d] "fmt"\n",                  \
            __func__, __LINE__, ##args);                    \
    } while (0)

#ifdef DEBUG_DDOS_INTERNAL
#define DEBUG_INTERNAL(fmt, args...)    do {                \
        fprintf(stdout, "[%s:%d] "fmt"\n",                  \
            __func__, __LINE__, ##args);                    \
    } while (0)
#else
#define DEBUG_INTERNAL(fmt, ...)    do { } while (0)
#endif

#else
#define DEBUG_LINE()                do { } while (0)
#define DEBUG_ERR(fmt, ...)         do { } while (0)
#define DEBUG_WARNING(fmt, ...)     do { } while (0)
#define DEBUG_ALWAYS(fmt, ...)      do { } while (0)
#define DEBUG_INTERNAL(fmt, ...)    do { } while (0)
#endif
