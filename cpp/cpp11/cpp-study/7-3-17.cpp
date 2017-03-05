#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> nums;

void Add(const int val) {
    auto print = [&] {
        for (auto s: nums)
            std::cout << s << '\t';
        std::cout << std::endl;
    };

    for (auto &s: nums)
        s += val;
    print();

    std::for_each(nums.begin(), nums.end(), 
            std::bind2nd(std::plus<int>(), val));
    print();

    std::transform(nums.begin(), nums.end(), nums.begin(),
            std::bind2nd(std::plus<int>(), val));
    print();

    std::for_each(nums.begin(), nums.end(), [=](int &i) {
            i += val;
            });
    print();
}

int main() {
    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
    }
    Add(10);

    return 0;
}
