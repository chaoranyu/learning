#include <iostream>

class ConvType {
public:
    ConvType(int i) { std::cout << "int\n"; }
    ConvType(char c) = delete;
    //ConvType(char c) { std::cout << "char\n"; } //
};

void Func(ConvType ct) {};

int main() {
    Func(3);
    Func('a');

    ConvType ci(3);
    ConvType cc('a');

    return 0;
}
