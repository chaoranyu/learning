#include <iostream>

template <typename T, typename U>
void PerfectForward(T && t, U &Func) {
    std::cout << t << "\tforwarded...\n";
    Func(std::forward<T>(t));
}

void RunCode(double && m) { }
void RunHome(double && h) { }
void RunComp(double && c) { }

int main() {
    PerfectForward(1.5, RunCode);
    PerfectForward(8, RunHome);
    PerfectForward(1.5, RunComp);

    return 0;
}
