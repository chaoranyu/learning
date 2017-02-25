#include <iostream>

class A
{
public:
    void f() { std::cout << "A::f() called\n"; }
};

class B : public A //"public" is needed, otherwise it's inherited privately
{
};

int main()
{
    B b;
    b.f();

    return 0;
}
