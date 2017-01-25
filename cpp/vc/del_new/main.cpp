#include <iostream>
#include <cstdio>

class A
{
public:
	A(int v = 8) : var(v)
	{
		file = fopen("test", "r");
	}
	~A()
	{
		fclose(file);
	}

private:
	int var;
	FILE *file;
};

int main()
{
    //in 64-bit os, check previous 8 bytes of pAa
    //in gdb: x/8g 0x613c20 (pAa = 0x613c30)
	A *pAa = new A[3];
	delete []pAa;

	return 0;
}
