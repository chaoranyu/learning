#include <iostream>

enum week {
    MONDAY,
    TUESDAY,
    WENDESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    DAY_NUM
};

//enum week test;
week test; // both right

int main() {
    std::cout << sizeof(test) << std::endl;
    std::cout << sizeof(week) << std::endl;

    return 0;
}
