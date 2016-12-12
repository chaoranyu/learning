#include <stdio.h>
#include <string.h>

void swap(void *vp1,
		  void *vp2,
		  int size)
{
	char buffer[size];
	memcpy(buffer, vp1, size);
	memcpy(vp1, vp2, size);
	memcpy(vp2, buffer, size);
}

int main(int argc, char **argv)
{
	int x = 7, y = 99;
	printf("x = %d, y = %d\n", x, y);
	swap(&x, &y, sizeof(int));
	printf("x = %d, y = %d\n", x, y);

	char *s1 = strdup("hello");
	char *s2 = strdup("world!!!!");
	printf("s1 = %s, s2 = %s\n", s1, s2);
	swap(&s1, &s2, sizeof(char *));
	printf("s1 = %s, s2 = %s\n", s1, s2);

    return 0;
}
