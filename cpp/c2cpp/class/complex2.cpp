#include <iostream>
using namespace std;

class Complex
{
public:
	friend ostream &operator<<(ostream &, const Complex &);
	Complex(double real, double img):real(real), img(img){}
	Complex operator+=(const  Complex &b)
	{
		real += b.real;
		img += b.img;
		return *this;
	}
	
private:
	double real, img;
};

// must be a friend function
ostream &operator<<(ostream &o, const Complex &c)
{
	o << c.real << "+" << c.img << "i";
	return o;
}

int main(void)
{
	Complex a(1.0, 2.0), b(3.0, 4.0);
	a += b;
	cout << a << endl;

	return 0;
}
