#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
const Comparable & median3(vector<Comparable> &a, int left, int right);

template<typename Comparable>
void quicksort(vector<Comparable> &a, int left, int right);

template<typename Comparable>
void insertionSort(vector<Comparable> &a, int left, int right);

// QuickSort algorithm (driver)
template<typename Comparable>
void quicksort(vector<Comparable> &a)
{
    quicksort(a, 0, a.size() - 1);
}

// Internal quicksort method that makes recursive calls
template<typename Comparable>
void quicksort(vector<Comparable> &a, int left, int right)
{
    if (left + 10 <= right) {
        Comparable pivot = median3(a, left, right);
        
        int i = left, j = right - 1;
        for (;;) {
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}
            if (i < j)
                std::swap(a[i], a[j]);
            else 
                break;
        }

        std::swap(a[i], a[right-1]); // Restore pivot

        quicksort(a, left, i - 1);
        quicksort(a, i + 1, right);
    } else {
        insertionSort(a, left, right);
    }
}

// Return median of left, center, and right
// Order these and hide the pivot
template<typename Comparable>
const Comparable & median3(vector<Comparable> &a, int left, int right)
{
    int center = (left + right) / 2;
    if (a[center] < a[left]) 
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

template<typename Comparable>
void insertionSort(vector<Comparable> &a, int left, int right)
{
	int j;

	for (int p = left + 1; p <= right; p++) {
		auto tmp = a[p];
		for (j = p; j > left && tmp < a[j-1]; j--) {
			a[j] = a[j-1];
		}
		a[j] = tmp;
	}
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

    quicksort(v);

    for(auto &a : v)
        std::cout << a << "\t";
    std::cout << std::endl;

    return 0;
}
