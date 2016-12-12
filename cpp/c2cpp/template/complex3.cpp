#include <iostream>
using namespace std;

template <class T>
T power(T a, int exp)
{
	T ans = a;
	while ( --exp > 0 )
		ans *= a;
	return (ans);
}

class Complex
{
	friend ostream &operator<<(ostream &, const Complex &);
public:
	Complex(double real, double img):real(real), img(img){}
	Complex operator+=(const  Complex &b)
	{
		real += b.real;
		img += b.img;
		return *this;
	}
	
	Complex operator*=(const  Complex &b)
	{
		double r, i;
		r = real*b.real - img*b.img;
		i = real*b.img + img*b.real;
		real = r;
		img = i;
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
	Complex a(0, 1);
	cout << power(a, 1) << endl
		 << power(a, 2) << endl
	     << power(a, 3) << endl
	     << power(a, 4) << endl;
	cout << power(1.1, 3) << endl;

	return 0;
}
