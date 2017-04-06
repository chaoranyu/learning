#include <iostream>
#include <cmath>

int main()
{
    unsigned int n;
    std::cin >> n;
    for (int i = 2; i < std::sqrt(n); i++)
    {
        if (n % i == 0)
        {
            std::cout << n << " is not prime\n";
            return 0; 
        }
    }

    std::cout << n << " is prime\n";
    return 0;
}
