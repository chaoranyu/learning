#include <stdio.h>

void main(void)
{
	int n, i;
	printf("Input number: ");
	scanf("%d", &n);
	printf("%d : ", n);
	for (i = 2; i < n/2 + 1;)
	{
		if (n % i == 0)
		{
			printf("%d ", i);
			n /= i;
		} else 
		{
			i++;
		}
	}
	printf("%d\n", n);
}
