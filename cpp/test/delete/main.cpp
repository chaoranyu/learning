#include <iostream>
#include <cstdio>
using namespace std;

class A
{
public:
    A(int v = 1) : var(v)
    {
        cout << "constructor" << endl;
        file = fopen("test", "r");
    }
    ~A()
    {
        cout << "destructor" << endl;
        fclose(file);
        cout << "destructor2" << endl;
    }

private:
    int var;
    FILE *file;
};

int main()
{
    A *pAa = new A[3];

    //delete [] pAa;
    delete pAa;

    return 0;
}
