#include <iostream>
using namespace std;

class C
{
    public:
        C(){ iCount++; }
        static int NofC(){ return iCount; }

    private:
        static int iCount;
};
int C::iCount = 0;

int main()
{   int t,n;
    C *cn;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << C::NofC() << endl;
        cn = new C[n];
        cout << C::NofC() << endl;
        delete []cn;
    }
    return 0;
}
