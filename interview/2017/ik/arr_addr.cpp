#include <iostream>

int main() {
    int a[3] {1, 2, 3};
    int *p, *q;
    p = &a[0];
    q = &a[2];

    std::cout << (char *)q - (char *)p << std::endl;
    std::cout << a[q-p] << std::endl;


    return 0;
}
