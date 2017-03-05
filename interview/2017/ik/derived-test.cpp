#include <iostream>

class A {
public:
    A() { std::cout << "A\n"; }
    ~A() { std::cout << "~A\n"; }
};

class B {
public:
    B() { std::cout << "B\n"; }
    ~B() { std::cout << "~B\n"; }
};

class C: public A {
public:
    C() { std::cout << "C\n"; }
    ~C() { std::cout << "~C\n"; }

private:
    B b;
};

int main() {
    C c;

    return 0;
}
