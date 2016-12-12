#include <iostream>
using namespace std;

int main()
{
	float f = 7.0;
	short s = *(short*)&f;
	cout<< s << endl;

	return 0;
}
