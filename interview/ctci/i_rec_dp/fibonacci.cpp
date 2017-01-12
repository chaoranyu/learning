#include <iostream>
#include <chrono>

int fibonacci(int i)
{
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

const int MAX = 50;
int *fib = new int[MAX];

int fibonacci_2(int i)
{
    if (i == 0) return 0;
    if (i == 1) return 1;
    if (fib[i] != 0) return fib[i];
    fib[i] = fibonacci_2(i-1) + fibonacci_2(i-2);
    return fib[i];
}
int main()
{
    int i = 40;

    auto start = std::chrono::system_clock::now();
    std::cout << fibonacci(i);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "(" << diff.count() << ")\n";

    start = std::chrono::system_clock::now();
    std::cout << fibonacci_2(i);
    end = std::chrono::system_clock::now();
    diff = end - start;
    std::cout << "(" << diff.count() << ")\n";

    return 0;
}
