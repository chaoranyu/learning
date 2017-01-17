#include <iostream>
#include <iomanip>

class Solution {
public:
    int findComplement(int num) {
        int mask = num;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;

        return num ^ mask;
    }

    //int findComplement(int num) {
    //    unsigned mask = ~0;
    //    while (num & mask) mask <<= 1;
    //    return num ^ ~mask;
    //}

    std::string toBin(int num) {
        std::string s;
        const char indices[3] = "01";
        while (num) {
            s = indices[num & 1] + s;
            num >>= 1;
        }

        return s;
    }
};

int main()
{
    Solution s;
    int num = 1001; // num is a positive integer
    int num2 = s.findComplement(num);
    std::string num_str = std::to_string(num);

    std::cout << num << "(" << s.toBin(num) << ")\n"
              << std::setw(num_str.length()) << num2 << "(" 
              << std::setw(s.toBin(num).length()) << s.toBin(num2) << ")\n";
	return 0;
}
