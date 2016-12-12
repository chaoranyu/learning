#include <iostream>
using namespace std;

struct Complex {
	double real, img;
};

Complex operator+(const Complex &a, const Complex &b)
{
	Complex sum;
	sum.real = a.real + b.real;
	sum.img = a.img + b.img;
	return sum;
}

ostream &operator<<(ostream &o, const Complex &c)
{
	o << c.real << "+" << c.img << "i";
	return o;
}

int main(void)
{
	Complex a = {1.0, 2.0}, b = {3.0, 4.0}, c;
	c = a + b;
	cout << c << endl;
	cout << c.real << "+" << c.img << "i" <<endl;

	return 0;
}
