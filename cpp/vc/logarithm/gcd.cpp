// logarithm.cpp
#include <iostream>

// greatest common divisor / highest common factor
long gcd(long m, long n);

int main(int argc, char* argv[])
{
	//long m = 1989, n = 1590;
	long m = 1366, n = 768;

    std::cout << "gcd(" << m << "," << n << ") = " << gcd(m, n) << '\n';
	
	return 0;
}

long gcd(long m, long n)
{
	while( n != 0 )
	{
		long rem = m % n;
		m = n;
		n = rem;
	}

	return m;
}
