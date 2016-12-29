#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main()
{
	std::vector<int> ivec = {1, 2, 3, 4};
	std::vector<std::string> svec = {"red", "green", "blue"};

	// C++11, you must use a specific type declaration.
	// i.e. auto lambda = [](int x, int y) {return x + y;};
	auto adder = [](auto op1, auto op2) {return op1 + op2;};
	std::cout << "int result: "
		<< std::accumulate(ivec.begin(), ivec.end(), 0, adder)
		<< '\n';

	std::cout << "string result: "
		<< std::accumulate(svec.begin(), svec.end(), std::string(""), adder)
		<< '\n';

	return 0;
}
