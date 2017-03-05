#include <iostream>

int main() {
    int x = 3, y = x++, z = y; // right
    std::cout << z << std::endl;

    //int yy = xx, xx = 4; // wrong
    //std::cout << yy << std::endl;

    return 0;
}
