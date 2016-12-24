#include <iostream>
#include <vector>

int main()
{
	std::vector<int> nums = {5, 2, 1, 6, 9};

	//for(auto const &n : nums)
	for(auto a : nums)
		std::cout << a << "  ";

	std::cout << std::endl;


	int arr[] = {5, 2, 1, 6, 9};

	for(auto a : arr)
		std::cout << a << "  ";

	std::cout << std::endl;

	return 0;
}
