#include <iostream>

class Base
{
public:
    void f(double i){ std::cout << "Base: " << i << std::endl; }
};

class Derived : Base
{
public:
    using Base::f;
    void f(int i){ std::cout << "Derived: " << i << std::endl; }
};

int main()
{
    Base b;
    b.f(4.5);

    Derived d;
    d.f(4.5);

    return 0;
}
