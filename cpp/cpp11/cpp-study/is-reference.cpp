#include <iostream>
#include <string>
#include <type_traits>

int main() {
    std::cout <<
        std::is_rvalue_reference<std::string &&>::value <<
        std::endl;
    
    return 0;
}
