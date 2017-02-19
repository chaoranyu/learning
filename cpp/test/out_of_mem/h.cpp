#include <iostream>
#include <cstring>
#include <string>

int foo()
{
    return foo();
}

int main()
{
    //foo();

    int h[10];
    for (int i = 0; i < 100; i++)
        h[i] = i;

    return 0;
}
