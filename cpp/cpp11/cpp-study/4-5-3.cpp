#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (auto & a : arr)
        a *= 2;

    for (auto e : arr)
        std::cout << e << "  ";
    std::cout << std::endl;

    return 0;
}
