#include <iostream>
//#include <cstddef>
using namespace std;

int main()
{
    int *p = nullptr;
    int n = 123;
    p = &n;

    cout << *p << endl;
}
