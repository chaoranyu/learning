#include <iostream>

struct A
{
    A(int i) { std::cout << "A(int i)\n"; }
    A(double d, int i) { std::cout << "A(double d, int i)\n"; }
    A(float f, int i, const char *c) {
        std::cout << "A(float f, int i, const char *c)\n";
    }
};

struct B : A
{
    using A::A;
    int d {0};
};

int main()
{
    B b(356);

    return 0;
}
