#include <iostream>

class A {
public:
    A() { std::cout << "A\n"; }
    A(int ii) : i(ii) { std::cout << "A " << i << '\n'; }
    ~A() { std::cout << "~A\n"; }
private:
    int i {0};
};

class B {
public:
    B() { std::cout << "B\n"; }
    ~B() { std::cout << "~B\n"; }
private:
    int j {0};
};

class C: public A {
public:
    using A::A;
    C(int kk) { std::cout << "C " << kk << std::endl; }
    ~C() { std::cout << "~C\n"; }

private:
    B b;
    int k {0};
};

int main() {
    C c(22);

    return 0;
}
