#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> nums = {2, 4, 1, 5, 1, 3, 6, 6};

	std::sort(nums.begin(), nums.end());
	nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

	for (auto a : nums) {
		std::cout << a << " ";
	}
	std::cout << "\n";

	return 0;
}
