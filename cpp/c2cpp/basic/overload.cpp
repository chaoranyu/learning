#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

int main()
{
	cout << add(1, 2) << endl
		<< add(1.1, 2.2) << endl
		<< add(3.3F, 4.4F) << endl;

	return 0;
}
