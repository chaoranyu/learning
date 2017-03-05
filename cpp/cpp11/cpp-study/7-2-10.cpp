// g++ -std=c++11 -c 7-2-10.cpp
#include <cstddef>
#include <new>

extern void *p;

class NoStackAlloc {
public:
    ~NoStackAlloc() = delete;
};

int main() {
    //NoStackAlloc nsa;
    new (p) NoStackAlloc(); // placement new

    return 1;
}
