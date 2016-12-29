#include <sstream>

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        std::istringstream iss(argv[1]);
        int val;

        if ((iss >> val) && iss.eof()) // Check eofbit
        {
            // Conversion successful
        }
    }

    return 0;
}
