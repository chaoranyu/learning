#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
void percDown(vector<Comparable> &a, int i, int n);

// Standard heapsort
template<typename Comparable>
void heapsort(vector<Comparable> &a)
{
    for (int i = a.size() / 2; i >= 0; i--) { // buildHeap
        percDown(a, i, a.size());
    }
    for (int j = a.size() - 1; j > 0; j--) { // deleteMax
        std::swap(a[0], a[j]);
        percDown(a, 0, j);
    }
}

// Internal method for heapsort
inline int leftChild(int i)
{
    return 2 * i + 1;
}

// Internal method for heapsort that is used in deleteMax and buildHeap
template<typename Comparable>
void percDown(vector<Comparable> &a, int i, int n)
{
	int child;
    Comparable tmp;

	for (tmp = a[i]; leftChild(i) < n; i = child) {
        child = leftChild(i);
        if (child != n - 1 && a[child] < a[child+1])
            child++;
        if (tmp < a[child])
            a[i] = std::move(a[child]);
        else
            break;
	}
    a[i] = std::move(tmp);
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(11);
    v.push_back(13);
    v.push_back(6);
    v.push_back(4);
    v.push_back(9);
    v.push_back(12);
    v.push_back(3);
    v.push_back(5);
    v.push_back(8);
    v.push_back(7);
    v.push_back(0);
    v.push_back(10);

    for(auto &a : v)
        std::cout << a << "\t";
    std::cout << std::endl;

    heapsort(v);

    for(auto &a : v)
        std::cout << a << "\t";
    std::cout << std::endl;

    return 0;
}
