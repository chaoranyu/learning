#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string text("The quick brown fox jumps over the lazy     dog.");
	std::cout << text << std::endl;

	std::regex re_x("\\S+");
	std::regex re_b(" ");

	std::cout << std::regex_replace(text, re_x, "x") << std::endl;
	std::cout << std::regex_replace(std::regex_replace(text, re_x, "x"), re_b, "") << std::endl;

	return 0;
}
