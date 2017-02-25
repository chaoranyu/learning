#include <iostream>

struct Copyable {
    Copyable() {}
    Copyable(const Copyable &o) {
        std::cout << "Copied\n";
    }
};

Copyable ReturnRvalue() { return Copyable(); }
void AcceptValue(Copyable o) {}
void AcceptRef(const Copyable &o) {}

int main() {
    std::cout << "Pass by value: \n";
    AcceptValue(ReturnRvalue());
    std::cout << "Pass by reference: \n";
    AcceptRef(ReturnRvalue());

    return 0;
}
