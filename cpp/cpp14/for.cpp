#include <iostream>
#include <vector>

int main()
{
	std::vector<int> nums = {5, 2, 1, 6, 9};

	//for(auto const &n : nums)
	for(int n : nums)
		std::cout << n << "\t";

	std::cout << std::endl;


	return 0;
}
