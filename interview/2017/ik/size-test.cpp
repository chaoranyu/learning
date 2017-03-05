#include <iostream>

typedef struct {
    short a;
    char b;
    short c;
    unsigned d;
    struct s {
        unsigned u : 3;
        unsigned v : 2;
    };
//#define s.u 1
//#define s.v 1
    unsigned h;
    unsigned i;
} head_t;

struct first_t {
    short a;
    char b;
    short c;
    unsigned d;
    struct s {
        unsigned u : 3;
        unsigned v : 2;
    };
};

struct second_t {
    short a;
    int b;
    short c;
};

struct third_t {
    struct s {
        int m;
        int n;
    };
};

struct s {
    int m : 12;
    int n : 18;
};

int main() {
    std::cout << sizeof(head_t) << std::endl;
    std::cout << sizeof(first_t) << std::endl;
    std::cout << sizeof(second_t) << std::endl;
    std::cout << sizeof(third_t) << std::endl;
    std::cout << sizeof(s) << std::endl;

    return 0;
}
