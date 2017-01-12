#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
void selectionSort(vector<Comparable> &a)
{
	int i, j, min;

	for (i = 0; i < a.size() - 1; i++) {
		min = i;
		for (j = i + 1; j < a.size(); j++) {
            if (a[min] > a[j])
                min = j;
		}
        std::swap(a[i], a[min]);
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

	selectionSort(v);

	for(auto iter : v)
		std::cout << iter << "\t";
	std::cout << std::endl;

	return 0;
}
