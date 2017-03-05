#include <iostream>
#include <typeinfo>

class White{};
class Black{};

int main() {
    White a;
    Black b;

    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;

    White c;

    bool a_b_sametype = (typeid(a).hash_code() == typeid(b).hash_code());
    bool a_c_sametype = (typeid(a).hash_code() == typeid(c).hash_code());

    std::cout << "Same type?\n";
    std::cout << "A and B? " << (int)a_b_sametype << std::endl;
    std::cout << "A and C? " << (int)a_c_sametype << std::endl;

    return 0;
}
