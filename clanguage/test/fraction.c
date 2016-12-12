#include <stdio.h>

int main()
{
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			for (int k = 1; k < 10; k++)
			{
				if ( i != j && j != k && 9 * i * k + j * k == 10 * i *j)
					printf("%d%d/%d%d\n", i, j, j, k);
			}

	return 0;
}
