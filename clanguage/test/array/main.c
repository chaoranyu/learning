#include <stdio.h>

int main()
{
	int a[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
//	int *pp = a[0];

//	printf("%d\n", *((pp+1)[2]));
	printf("%d\n", *((a+1)[2]));
	printf("%d\n", (*(a+1))[2]);
	printf("%d\n", *(*(a+1)+2));
	printf("%d\n", *(a+2));

	return 0;
}
