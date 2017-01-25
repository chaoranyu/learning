// logarithm.cpp

#include <iostream>
#include <vector>

const int NOT_FOUND = -1;

// binary search
template <typename Comparable>
int binarySearch(const std::vector<Comparable> & a, const Comparable x);

int main(int argc, char* argv[])
{
    std::vector<int> v;

	for(int i = 0; i < 50; i++)
		v.push_back(2*i + 1);

	for(auto &a : v)
	{
        std::cout << a << "\t";
	}

    std::cout << "\nEnter the number: ";
	int k;
    std::cin >> k;
    std::cout << "The id is " << binarySearch(v, k) << '\n';

	return 0;
}

template <typename Comparable>
int binarySearch(const std::vector<Comparable> & a, const Comparable x)
{
	int low = 0, high = a.size() - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if( a[mid] < x )
			low = mid + 1;
		else if(a[mid] > x)
			high = mid - 1;
		else
			return mid;
	}

	return NOT_FOUND;
}
