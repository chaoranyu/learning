#include <stdio.h>
#include <string.h>

int main()
{
	const char *part1 = "Hello, ";
	const char *part2 = "Garfield. ";
	const char *part3 = "I'm ";
	const char *part4 = "Doraemon.";
	char buffer[256]; /* assume that `size` is calculated properly */
	int i = 0;
	
	strcpy(buffer, part1);
	strcat(buffer, part2);
	strcat(buffer, part3);
	strcat(buffer, part4);
	printf("[%d] strcpy: %s\n", ++i, buffer);

	stpcpy(stpcpy(stpcpy(stpcpy(buffer, part1), part2), part3), part4);
	printf("[%d] stpcpy: %s\n", ++i, buffer);

	char *end = buffer;
	end = stpcpy(end, part1);
	end = stpcpy(end, part2);
	end = stpcpy(end, part3);
	end = stpcpy(end, part4);
	printf("[%d] stpcpy: %s\n", ++i, buffer);
}
