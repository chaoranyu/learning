#include <stdio.h>

/* lower: convert c to lower case; ASCII only */
int lower1(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
int lower2(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
int lower3(int c)
{
	return (unsigned char)(c | 0x20);
}

void main()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		/* putchar(lower1(c)); */
		/* putchar(lower2(c)); */
		/* putchar(lower3(c)); */
		printf("%c\n", lower1(c));
		/* printf("%c\n", (char)lower2(c)); */
		/* printf("%c\n", (char)lower3(c)); */
		/* fflush(stdin); */
	}
}
