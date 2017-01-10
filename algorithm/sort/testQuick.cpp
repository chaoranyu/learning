#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int left, int right);

void quickSort(vector<int> &arr, int left, int right) {
    int index = partition(arr, left, right);
    if (left < index - 1) { // Sort left half
        quickSort(arr, left, index - 1);
    }
    if (index < right) { // Sort right half
        quickSort(arr, index, right);
    }
}

int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[(left + right) / 2]; // Pick pivot point
    while (left <= right) {
        // Find element on left that should be on right
        while (arr[left] < pivot) left++;

        // Find element on right that should be on left
        while (arr[right] > pivot) right--;

         // Swap elements, and move left and right indices
        if (left <= right) {
            std::swap(arr[left], arr[right]); // swaps elements
            left++;
            right--;
        }
    }
    return left;
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

    quickSort(v, 0, v.size() - 1);

    for(auto &a : v)
        std::cout << a << "\t";
    std::cout << std::endl;

    return 0;
}
