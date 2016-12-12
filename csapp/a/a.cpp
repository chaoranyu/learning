#include <iostream>
using namespace std;

int main()
{
	int x = 53191;
	short sx = (short) x;
	int y = sx;

	cout << "x = " << x << ", sx = " << sx
		<< ", y = " << y << endl;
}
