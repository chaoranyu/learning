#include <iostream>

class HasPtrMem {
public:
    HasPtrMem() : d(new int(0)) {}
    HasPtrMem(const HasPtrMem &h) :
        d(new int(*h.d)) {}
    ~HasPtrMem() { delete d; }

    int *d;
};

int main()
{
    HasPtrMem a;
    HasPtrMem b(a);
    std::cout << *a.d << std::endl;
    std::cout << *b.d << std::endl;

    return 0;
}
