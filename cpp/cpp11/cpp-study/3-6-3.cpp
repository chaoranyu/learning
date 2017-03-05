#include <type_traits>
#include <iostream>

struct SLayout1 {};

struct SLayout2 {
private:
    int x;
    int y;
};

struct SLayout3 : SLayout1 {
    int x;
    int y;
    void f();
};

struct SLayout4 : SLayout1 {
    int x;
    SLayout1 y;
};

struct SLayout5 : SLayout1, SLayout3 {};

struct SLayout6 { static int y; };

struct SLayout7 : SLayout6 { int x; };

struct NonSLayout1 : SLayout1 {
    SLayout1 x;
    int i;
};

struct NonSLayout2 : SLayout2 { int z; };

struct NonSLayout3 : NonSLayout2 {};

struct NonSLayout4 {
public:
    int x;
private:
    int y;
};

int main() {
    std::cout << std::is_trivial<SLayout1>::value << std::endl; // 1
    std::cout << std::is_trivial<SLayout2>::value << std::endl; // 1
    std::cout << std::is_trivial<SLayout3>::value << std::endl; // 1
    std::cout << std::is_trivial<SLayout4>::value << std::endl; // 1
    std::cout << std::is_trivial<SLayout5>::value << std::endl; // 1
    std::cout << std::is_trivial<SLayout6>::value << std::endl; // 1
    std::cout << std::is_trivial<SLayout7>::value << std::endl; // 1

    std::cout << std::is_trivial<NonSLayout1>::value << std::endl; // 0?
    std::cout << std::is_trivial<NonSLayout2>::value << std::endl; // 0?
    std::cout << std::is_trivial<NonSLayout3>::value << std::endl; // 0?
    std::cout << std::is_trivial<NonSLayout4>::value << std::endl; // 0?

    return 0;
}
