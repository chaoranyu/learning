#include <stdio.h>
#include <assert.h>

extern void test_a(int value);
extern void test_b(int value);

int main()
{
    test_a(5 >= 3);
    test_b(5 == 3);

    return 0;
}
