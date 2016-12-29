#include <iostream>
#include <sstream>

bool divide_a(int val);
bool divide_b(int val);
bool divide_c(int val);

int main(int argc, char *argv[])
{
	int val = 65536;
    if (argc >= 2)
    {
        std::istringstream iss(argv[1]);
        //int val;

        if (!(iss >> val) || !iss.eof()) // Check eofbit
        {
            // Conversion fails
			std::cerr << "invalid num: " << argv[1] << '\n';
			return -1;
        }
    }

	std::cout << "val = " << val << '\n'; 
	std::cout << divide_a(val) << '\n';
	std::cout << divide_b(val) << '\n';
	std::cout << divide_c(val) << '\n';

	return 0;
}

bool divide_a(int val)
{
	return val % 16 == 0;
}

bool divide_b(int val)
{
	 // priority of & is higher than ==
	 // you can't write if (val & 0xF == 0)
	return (val & 0xF) == 0;
}

bool divide_c(int val)
{
	return (val >> 4 ) << 4 == val;
}
