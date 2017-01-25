#include <iostream>

int main()
{
    int count = 0;
    for (; 1;)
    {
        count++;
        if (count == 10)
            break;
    }
    std::cout << "count = " << count << std::endl;

    return 0;
}
