#include <iostream>

struct B1 {};
struct B2 {};

struct D1 : B1 {
    B1 b;
    int i;
};

struct D2 : B1 {
    B2 b;
    int i;
};

int main() {
    D1 d1;
    D2 d2;
    std::cout << std::hex;
    std::cout << reinterpret_cast<long long>(&d1) << std::endl;     // 7ffd6b5e4700
    std::cout << reinterpret_cast<long long>(&d1.b) << std::endl;   // 7ffd6b5e4701
    std::cout << reinterpret_cast<long long>(&d1.i) << std::endl;   // 7ffd6b5e4704

    std::cout << reinterpret_cast<long long>(&d2) << std::endl;     // 7ffd6b5e4710
    std::cout << reinterpret_cast<long long>(&d2.b) << std::endl;   // 7ffd6b5e4710
    std::cout << reinterpret_cast<long long>(&d2.i) << std::endl;   // 7ffd6b5e4714

    return 0;
}
