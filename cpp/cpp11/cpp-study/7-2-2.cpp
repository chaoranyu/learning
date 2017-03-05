#include <type_traits> // can be omitted?
#include <iostream>

class TwoCstor {
public:
    TwoCstor() = default;
    TwoCstor(int i) : data(i) {}

private:
    int data;
};

int main() {
    std::cout << std::is_pod<TwoCstor>::value << std::endl;

    return 0;
}
