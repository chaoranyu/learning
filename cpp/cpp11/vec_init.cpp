#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec{1, 9, 9, 8};

	for (auto i : vec) {
		cout << i << endl;
	}

	return 0;
}
