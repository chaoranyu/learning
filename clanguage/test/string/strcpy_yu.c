#include <stdio.h>
#include <assert.h>

char *strcpy_yu(char *des, const char *source)
{
	assert( des != NULL && source != NULL);
	char *r = des;

	while ((*des++ = *source++) != '\0');

	return r;
}

int main()
{
	char s[] = "hello, world";
	char t[20];

	printf("%s\n", s);
	strcpy_yu(t, s);
	printf("%s\n", t);

	return 0;
}
