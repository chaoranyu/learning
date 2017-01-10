#include <iostream>
#include <vector>
using namespace std;

// Shellsort, using Shell's (poor) increments.
template<typename Comparable>
void shellsort(vector<Comparable> &a)
{
    for (int gap = a.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < a.size(); i++) {
            auto tmp = std::move(a[i]);
            int j = i;

            for ( ; j >= gap && tmp < a[j-gap]; j -= gap) {
                a[j] = std::move(a[j-gap]);
            }
            a[j] = std::move(tmp);
        }
    }
}

int main()
{
    vector<int> v;
    v.push_back(81);
    v.push_back(94);
    v.push_back(11);
    v.push_back(96);
    v.push_back(12);
    v.push_back(35);
    v.push_back(17);
    v.push_back(95);
    v.push_back(28);
    v.push_back(58);
    v.push_back(41);
    v.push_back(75);
    v.push_back(15);

    for(auto &a : v)
        std::cout << a << "\t";
    std::cout << std::endl;

    shellsort(v);

    for(auto &a : v)
        std::cout << a << "\t";
    std::cout << std::endl;

    return 0;
}
