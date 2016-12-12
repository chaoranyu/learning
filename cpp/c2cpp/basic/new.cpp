#include <iostream>
using namespace std;

int main()
{
	int *pNum = new int(1);
	cout << *pNum << endl;
	delete pNum;

	int Num = 2;
	cout << Num << endl;

	return 0;
}
