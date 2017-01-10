#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
void mergeSort(vector<Comparable> &a,
               vector<Comparable> &tmpArray, int left, int right);
template<typename Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &tmpArray,
           int leftPos, int rightPos, int rightEnd);

// Mergesort algorithm (driver)
template<typename Comparable>
void mergeSort(vector<Comparable> &a)
{
    vector<Comparable> tmpArray(a.size());

    mergeSort(a, tmpArray, 0, a.size() - 1);
}

// Internal method that makes recursive calls
template<typename Comparable>
void mergeSort(vector<Comparable> &a,
               vector<Comparable> &tmpArray, int left, int right)
{
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

// Internal method that merges two sorted halves of a subarray
template<typename Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &tmpArray,
           int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] < a[rightPos])
            tmpArray[tmpPos++] = std::move(a[leftPos++]);
        else
            tmpArray[tmpPos++] = std::move(a[rightPos++]);
    }

    while (leftPos <= leftEnd) {
        tmpArray[tmpPos++] = std::move(a[leftPos++]);
    }

    while (rightPos <= rightEnd) {
        tmpArray[tmpPos++] = std::move(a[rightPos++]);
    }

    for (int i = 0; i < numElements; i++, rightEnd--) {
        a[rightEnd] = std::move(tmpArray[rightEnd]);
    }
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(13);
    v.push_back(24);
    v.push_back(26);
    v.push_back(2);
    v.push_back(15);
    v.push_back(27);
    v.push_back(38);

    for(auto &a : v)
        std::cout << a << "\t";
    std::cout << std::endl;

    mergeSort(v);

    for(auto &a : v)
        std::cout << a << "\t";
    std::cout << std::endl;

    return 0;
}
