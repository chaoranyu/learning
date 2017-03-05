#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main()
{
    vector<bool> v;
    v.push_back(true);
    auto var = v[0];
    cout << typeid(var).name() << endl;

    vector<int> v2;
    v2.push_back(3);
    auto var2 = v2[0];
    cout << typeid(var2).name() << endl;
}
