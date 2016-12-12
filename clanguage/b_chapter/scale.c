#include <stdio.h>
int main()
{
	short int a,b;
	a = 0x0000;
	b = 0x0001;
	printf( "%d %d ",a,b );
	a = 0xFFFE;
	b = 0xFFFF;
	printf( "%d %d ",a,b );
	a = 0x7FFF;
	b = 0x8000;
	printf( "%d %d\n",a,b );
	return 0;
}
