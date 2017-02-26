#include <iostream>

struct Maythrow {
    Maythrow() {}
    Maythrow(const Maythrow &) {
        std::cout << "Maythrow copy constructor.\n";
    }
    Maythrow(Maythrow &&) {
        std::cout << "Maythrow move constructor.\n";
    }
};


struct Nothrow {
    Nothrow() {}
    Nothrow(const Nothrow &) {
        std::cout << "Nothrow copy constructor.\n";
    }
    Nothrow(Nothrow &&) noexcept {
        std::cout << "Nothrow move constructor.\n";
    }
};

int main() {
    Maythrow m;
    Nothrow n;

    Maythrow mt = std::move_if_noexcept(m);
    Nothrow nt = std::move_if_noexcept(n);
    
    return 0;
}
