#include <stdio.h>
#include <string.h>

typedef struct
{
	char s[3];
	unsigned char a : 4,
				  b : 4;
} test_t;

typedef struct
{
	char s[3];
	unsigned char a : 4;
	unsigned char b : 4;
} __attribute__((__aligned__(8))) test2_t;

int main()
{
	test_t foo;
	unsigned int bar = 0x12345678;

	memcpy(&foo.s[0], &bar, sizeof(bar));
	printf("s = [ %x %x %x ], a = %u, b = %u\n",
			foo.s[0], foo.s[1], foo.s[2], foo.a, foo.b);

	test_t foo2;
	//memcpy(&foo2.s[0], &bar, sizeof(bar));
	memcpy(&foo2, &bar, sizeof(bar));
	printf("s = [ %x %x %x ], a = %u, b = %u\n",
			foo2.s[0], foo2.s[1], foo2.s[2], foo2.a, foo2.b);

	return 0;
}
