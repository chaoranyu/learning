#include <iostream>

int main() {
    int x[3] = {8};
    int y[3] = x;

    for (auto & i : x)
        std::cout << i << std::endl;

    for (auto & i : y)
        std::cout << i << std::endl;

    return 0;
}
