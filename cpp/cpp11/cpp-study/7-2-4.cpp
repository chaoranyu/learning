#include <type_traits> // can be omitted?
#include <iostream>

class NoCopyCstor {
public:
    NoCopyCstor() = default;
    NoCopyCstor(const NoCopyCstor &) = delete;
};

int main() {
    NoCopyCstor a;
    NoCopyCstor b(a);

    return 0;
}
