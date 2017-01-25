#include <iostream>

int partition(int arr[], int l, int r);
void quicksort(int arr[], int l, int r);

int main()
{
	int arr[9] = { 3, 7, 8, 5, 2, 1, 9, 5, 4 };
	quicksort(arr, 0, 8);
	for (int i = 0; i < 9; i++)
		std::cout << arr[i] << "   ";
    std::cout << std::endl;

	return 0;
}

void quicksort(int arr[], int l, int r) {
	if (l < r) {
		int pivot = partition(arr, l, r);
		quicksort(arr, l, pivot - 1);
		quicksort(arr, pivot + 1, r);
	}
}

int partition(int arr[], int l, int r) {
	int k = l, pivot = arr[r];
	for (int i = l; i < r; ++i)
		if (arr[i] <= pivot)
			std::swap(arr[i], arr[k++]);
	std::swap(arr[k], arr[r]);

	return k;
}
