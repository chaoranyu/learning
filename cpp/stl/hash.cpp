#include <iostream>
#include <functional>
//#include <string>
#include <iomanip>

int main()
{
	std::string str = "Meet the new boss ...";
	std::size_t str_hash = std::hash<std::string>{}(str);
	std::cout << "hash(" << std::quoted(str) << ") = " << str_hash << "\n";

	return 0;
}
