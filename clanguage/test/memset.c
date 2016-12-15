#include <stdio.h>
#include <string.h>

void main()
{
	int arr[10];
	memset(arr, 1, sizeof(arr));

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}
