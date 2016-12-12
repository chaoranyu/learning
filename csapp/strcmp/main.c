#include <stdio.h>
#include "test.h"

int main()
{
	char *s1 = "123";
	char *d1 = "1234";

	printf("%d\n", strcmp_test(s1, d1));

	char *s2 = "123";
	char *d2 = "121";

	printf("%d\n", strcmp_test(s2, d2));

	char *s3 = "111";
	char *d3 = "123";

	printf("%d\n", strcmp_test(s3, d3));
}
