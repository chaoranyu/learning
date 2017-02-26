#include <iostream>

void Fun(std::initializer_list<int> iv) {
    for (auto &a : iv)
        std::cout << a << "  ";
    std::cout << std::endl;
}

int main() {
    Fun({1, 3, 5});
    Fun({});

    return 0;
}
