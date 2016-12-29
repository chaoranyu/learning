#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, std::string> u = {
		{"RED", "#FF0000"},
		{"GREEN", "#00FF00"},
		{"BLUE", "#0000FF"}
	};

	for (const auto& n : u) {
		std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
	}

	u["BLACK"] = "#000000";
	u["WHITE"] = "#FFFFFF";

	std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
	std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";

	return 0;
}
