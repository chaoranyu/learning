#include <stdio.h>

int main()
{
    int steps = 256 * 1024 * 1024;
    int a[2] = {1, 13333};

    //Loop1
    //for (int i=0; i<steps; i++)  { a[0]++; a[0]++; }
    //Loop2
    for (int i=0; i<steps; i++)  { a[0]++; a[1]++; }

	return 0;
}
