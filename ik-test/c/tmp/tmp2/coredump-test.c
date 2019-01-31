#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p = NULL;
	int i;

	for (i = 0; i < 20; i++)
	{
		printf("%02d  ", i);
		fflush(stdout);
		sleep(1);

		if (i == 5)
			abort();
			//*p = 134;
	}

	printf("\n\n");

	return 0;
}
