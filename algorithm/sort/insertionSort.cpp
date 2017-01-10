#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
void insertionSort(vector<Comparable> &a)
{
	int j;

	for (int p = 1; p < a.size(); p++) {
		auto tmp = std::move(a[p]);
		for (j = p; j > 0 && tmp < a[j-1]; j--) {
			a[j] = std::move(a[j-1]);
		}
        a[j] = std::move(tmp);
	}
}

int main()
{
	vector<int> v;
	v.push_back(34);
	v.push_back(8);
	v.push_back(64);
	v.push_back(54);
	v.push_back(32);
	v.push_back(21);

	for(auto iter : v)
		std::cout << iter << "\t";
	std::cout << std::endl;

	insertionSort(v);

	for(auto iter : v)
		std::cout << iter << "\t";
	std::cout << std::endl;


	return 0;
}
