#include <stdio.h>
#include <assert.h>

void test_a(int value)
{
    assert(value);
    printf("%s: %d\n", __FUNCTION__, value);
}
