#include <iostream>
#include <cstring>
#include <string>

int main()
{
    const int MAX_LENGTH = 16;
    char dest[MAX_LENGTH];
    char test[MAX_LENGTH] = "aaaabbbbccccddd";
    std::cout << test << std::endl;

    std::string source = "hello, world! I am yu, a programmer.";
    strcpy(dest, source.c_str());
    std::cout << test << std::endl;
    std::cout << dest << std::endl;

    return 0;
}
