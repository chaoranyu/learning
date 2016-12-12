#include <iostream>
using namespace std;

int test1();
int test2();

int main()
{
    cout << test1() << endl;
    cout << test2() << endl;

    return 0;
}

int test1()
{
    int k = 10;
    const int &ref = k;
    int &x = const_cast<int&>(ref);
    x = 11;

    return k;
}

int test2()
{
    const int k = 10;
    //int &x = const_cast<int>(k);
    //x = 11;
    int x = 11;

    return k;
}
