#include <iostream>
using namespace std;

int main()
{
    cout << "Standard Clib: " << __STDC_HOSTED__ << endl;
    cout << "Standard C: " << __STDC__ << endl;
    //cout << "C standard version: " << __STDC_VERSION__ << endl;
    cout << "ISO/IEC " << __STDC_ISO_14882__ << endl;

    return 0;
}
