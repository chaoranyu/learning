#include <iostream>

int main() {
    int j = 12;
    auto by_val_lambda = [=] { return j + 1; };
    auto by_ref_lambda = [&] { return j + 1; };
    std::cout << "by_val_lambda: " << by_val_lambda() << std::endl;
    std::cout << "by_ref_lambda: " << by_ref_lambda() << std::endl;

    j++;
    std::cout << "by_val_lambda: " << by_val_lambda() << std::endl;
    std::cout << "by_ref_lambda: " << by_ref_lambda() << std::endl;

    return 0;
}
