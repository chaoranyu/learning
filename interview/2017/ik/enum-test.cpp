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

enum week test_a;
week test_b; // both right

int main() {
    std::cout << sizeof(test_a) << std::endl;
    std::cout << sizeof(week) << std::endl;

    //week e_day = reinterpret_cast<week>(2); // wrong
    week e_day = THURSDAY;
    std::cout << e_day << std::endl;

    return 0;
}
