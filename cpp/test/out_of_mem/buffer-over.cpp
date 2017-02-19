#include <iostream>
#include <cstring>
#include <string>

int main()
{
    const int MAX_LENGTH = 16;
    int a = 0x12341234; // variable in stack is reverse allocated?
    char dest[MAX_LENGTH];
    //char test[MAX_LENGTH] = "aaaabbbbccccddd";
    int b = 0x56785678;
    //std::cout << test << std::endl;

    std::string source = "hello, world! I am a programmer.";
    strcpy(dest, source.c_str());
    //std::cout << test << std::endl;
    std::cout << dest << std::endl;

    return 0;
}
