// 在GCC编译程序的时候，加上-ggdb3参数
//
// (gdb) info macro xxx
// (gdb) macro expand xxx
#include <stdio.h>

#define swap1(a, b) do {    \
    /*typeof(a) tmp;*/      \
    int tmp = (a);          \
    (a) = (b);              \
    (b) = tmp;              \
} while(0)

int main()
{
    int a = 1;
    int b = 3;

    printf("a = %d, b = %d\n", a, b);

    swap1(a, b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
