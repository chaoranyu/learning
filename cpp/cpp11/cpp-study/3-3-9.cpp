#include <iostream>

void RunCode(int && m) { std::cout << "rvalue ref\n"; }
void RunCode(int & m) { std::cout << "lvalue ref\n"; }
void RunCode(const int && m) { std::cout << "const rvalue ref\n"; }
void RunCode(const int & m) { std::cout << "const lvalue ref\n"; }

template <typename T>
void PerfectForward(T && t) { RunCode(std::forward<T>(t)); }

int main() {
    int a;
    int b;
    const int c = 1;
    const int d = 1;

    PerfectForward(a);
    PerfectForward(std::move(b));
    PerfectForward(c);
    PerfectForward(std::move(d));

    return 0;
}
