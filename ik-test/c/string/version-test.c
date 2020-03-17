#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	int res;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	res = strverscmp(argv[1], argv[2]);

	printf("%s %s %s\n", argv[1],
			(res < 0) ? "<" : (res == 0) ? "==" : ">", argv[2]);

	exit(EXIT_SUCCESS);
}
