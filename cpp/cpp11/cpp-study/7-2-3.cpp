#include <type_traits> // can be omitted?
#include <iostream>

class NoCopyCstor {
public:
    NoCopyCstor() = default;

private:
    NoCopyCstor(const NoCopyCstor &); // {}
};

int main() {
    NoCopyCstor a;
    NoCopyCstor b(a);

    return 0;
}
