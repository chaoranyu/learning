#include <iostream>
using namespace std;

int main()
{
	int i = 37;
	float f = *(float *)&i;
	cout<< f<< endl;

	return 0;
}
