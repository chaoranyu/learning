#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1; //high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			/* found match */
			return mid;
	}
	return -1; /* no match */
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1; //high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			/* found match */
			return mid;
	}
	return -1;
}

void main()
{
	int v[10] = {1, 3, 5, 7, 9, 11, 23, 35, 47, 59};
	int index = binsearch(47, v, 10);
	printf("array is: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", v[i]);
	printf("\nfound at %d\n", index);
}
