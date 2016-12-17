#include <iostream>
#include <sstream>
//#include <iomanip>

int main(int argc, char *argv[])
{
	std::istringstream iss(argv[1]);
	int num;
	if (!(iss >> num) || !iss.eof()) {
		std::cerr << "invalid num: " << argv[1] << "\n";
		return -1;
	} else {
		std::cout << "input: " << num << "\n";
		//std::setbase(16);
		std::cout << std::hex << "input: " << num << "\n";
	}

	for (int i = 0; i < 10; i++) {
		num >>= 4;
		std::cout << num << " ";
	}

	std::cout << "\n";

	return 0;
}
