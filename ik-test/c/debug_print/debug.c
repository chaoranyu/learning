#include <stdio.h>

#define DEBUG_LINE() printf("[%s:%s] line=%d\r\n",__FILE__, __func__, __LINE__)
#define DEBUG_ERR(fmt, args...) printf("\033[46;31m[%s:%d] "fmt"\033[0m\r\n", __func__, __LINE__, ##args)
#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%d] "#fmt"\033[0m\r\n", __func__, __LINE__, ##args)

void test()
{
    int number = 666;
    //DEBUG_ERR(important info);
    DEBUG_ERR("important info");
    DEBUG_ERR("number = %d, lalala", number);
    DEBUG_INFO(number = %d, number);
}

#define MOD_DEBUG_ERR(fmt, args...)  DEBUG_ERR("[DDos] "fmt, ##args)
//#define MOD_DEBUG_ERR(fmt, args...)  printf("\033[46;31m[DDos] ");DEBUG_ERR(fmt, ##args)
#define MOD_DEBUG_INFO(fmt, args...) printf("\033[33m[DDos]");DEBUG_INFO(fmt, ##args)
//#define MOD_DEBUG_INFO(fmt, args...) DEBUG_INFO([DDos] fmt, ##args)

void module_test()
{
    int number = 888;
    MOD_DEBUG_ERR("important info");
    //MOD_DEBUG_ERR(important info);
    MOD_DEBUG_INFO(number = %d, number);
}

int main()
{
    test();

    module_test();

    return 0;
}
