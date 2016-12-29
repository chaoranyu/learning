#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

int main()
{
	std::array<int, 10> myarray;

	for (int i = 0; i < 10; i++) myarray.at(i) = i + 1;

	std::cout << "myarray contains:";
	for (int i = 0; i < 10; i++)
		std::cout << ' ' << myarray[i];
	std::cout << '\n';

	return 0;
}
