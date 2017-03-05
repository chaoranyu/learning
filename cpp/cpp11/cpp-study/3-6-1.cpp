#include <type_traits>
#include <iostream>

struct Trivial1 {};

struct Trivial2 {
public:
    int a;
private:
    int b;
};

struct Trivial3 {
    Trivial1 a;
    Trivial2 b;
};

struct Trivial4 {
    Trivial2 a[23];
};

struct Trivial5 {
    int x;
    static int y;
};

struct NoTrivial1 {
    NoTrivial1() : z(43) {}
    int z;
};

struct NoTrivial2 {
    NoTrivial2(); // use =default here, it'll be  trivial
    int w;
};
NoTrivial2::NoTrivial2() = default;

struct NoTrivial3 {
    Trivial5 c;
    virtual void f();
};

int main() {
    std::cout << std::is_trivial<Trivial1>::value << std::endl; // 1
    std::cout << std::is_trivial<Trivial2>::value << std::endl; // 1
    std::cout << std::is_trivial<Trivial3>::value << std::endl; // 1
    std::cout << std::is_trivial<Trivial4>::value << std::endl; // 1
    std::cout << std::is_trivial<Trivial5>::value << std::endl; // 1
    std::cout << std::is_trivial<NoTrivial1>::value << std::endl; // 0
    std::cout << std::is_trivial<NoTrivial2>::value << std::endl; // 0
    std::cout << std::is_trivial<NoTrivial3>::value << std::endl; // 0
    

    return 0;
}
