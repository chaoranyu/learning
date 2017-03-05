#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto i = v.begin(); i != v.end(); i++)
        std::cout << *i << "  ";
    std::cout << std::endl;

    for (auto e : v)
        std::cout << e << "  ";
    std::cout << std::endl;

    return 0;
}
