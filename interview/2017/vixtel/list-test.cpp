#include <list>
#include <iostream>

int main()
{
    std::list<int> c{1, 3, 3, 5, 1, 7, 3, 9};
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    // method 1
    c.remove(3);
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    c.remove_if([](int n) { return n < 8; });
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    return 0;
}
