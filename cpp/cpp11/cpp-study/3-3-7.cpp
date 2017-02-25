// g++ -std=c++11 3-3-7.cpp -fno-elide-constructors
#include <iostream>

class HugeMem {
public:
    HugeMem(int size) : sz(size > 0 ? size : 1) {
        c = new int[sz];
    }
    ~HugeMem() {
        delete [] c;
    }
    HugeMem(HugeMem && hm) : c(hm.c) {
        hm.c = nullptr;
    }

    int *c;
    int sz;
};

class Movable {
public:
    Movable() : i(new int(3)), h(1024) {}
    ~Movable() { delete i; }
    Movable(Movable && m) :
        i(m.i), h(std::move(m.h)) {
        m.i = nullptr;
    } 

    int *i;
    HugeMem h;
};

Movable GetTemp() {
    Movable tmp;
    std::cout << std::hex << "Huge Mem from " <<
        __func__<< " @" << tmp.h.c << std::endl;
    return tmp;
}

int main()
{
    Movable a(GetTemp());
    std::cout << std::hex << "Huge Mem from " <<
        __func__<< " @" << a.h.c << std::endl;

    return 0;
}
