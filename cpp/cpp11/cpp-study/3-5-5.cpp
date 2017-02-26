#include <iostream>

int main()
{
    const int x = 1024;
    const int y = 10;

    char a = x;
    char *b = new char(1024);

    //char c = {x};   //cannot be complied
    char d = {y};
    //unsigned char e {-1};   //cannot be compiled

    float f {7};
    //int g {2.0F};   //cannot be compiled
    //float *h = new float{1e48}; //cannot be compiled
    float i = 1.2L;

    std::cout << (int)a << '\n';
    std::cout << (int)*b << '\n';
    std::cout << (int)d << '\n';
    std::cout << f << '\n';
    std::cout << i << '\n';

    return 0;
}
