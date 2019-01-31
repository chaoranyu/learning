#include <stdio.h>

int main()
{
    // snprintf: A terminating null character is automatically appended.
    // char s[32];
    // snprintf(s, sizeof(s), "hello"); // good
    // snprintf(s, sizeof(s), "hello%c", 0); // bad

	printf("%d%c\n", 11, 0); // 0 --> '\0'
	printf("%c\n", 100); // 100 --> 'd'

	return 0;
}
