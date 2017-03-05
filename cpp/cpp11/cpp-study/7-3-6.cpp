#include <iostream>

class AirportPrice {
public:
    AirportPrice(float rate) : _dutyfreerate(rate) {}
    float operator() (float price) {
        return price * (1 - _dutyfreerate/100);
    }

private:
    float _dutyfreerate;
};

int main() {
    float tax_rate = 5.5f;
    AirportPrice Changi(tax_rate);

    auto Changi2 =
        [tax_rate](float price)->float{ return price * (1 - tax_rate/100); };

    std::cout << Changi(3699) << std::endl;
    std::cout << Changi2(2899) << std::endl;

    return 0;
}
