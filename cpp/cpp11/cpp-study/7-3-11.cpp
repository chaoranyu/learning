#include <iostream>

int main() {
    int val = 0;

    //auto const_val_lambda = [=]() { val = 3; };
    std::cout << val << std::endl;

    auto mutable_val_lambda = [=]() mutable { val = 5; };
    mutable_val_lambda();
    std::cout << val << std::endl;

    auto const_ref_lambda = [&] { val = 7; };
    const_ref_lambda();
    std::cout << val << std::endl;

    auto const_param_lambda = [&](int v) { v = 9; };
    const_param_lambda(val);
    std::cout << val << std::endl;

    return 0;
}
