// g++ -std=c++11 3-3-6.cpp -fno-elide-constructors
#include <iostream>

class Movable {
public:
    Movable() : i(new int(3)) {}
    ~Movable() { delete i; }
    Movable(const Movable &m) : i(new int(*m.i)) {} 
    Movable(Movable &&m) : i(m.i) {
        m.i = nullptr;
    } 

    int *i;
};

int main()
{
    Movable a;

    Movable c(std::move(a));        // Move constructor called
    std::cout << *a.i << std::endl; // Segmentation fault

    return 0;
}
