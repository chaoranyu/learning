#include <stdio.h>

int main()
{
	char magic[16+1] = "ja\x01sd\xfahe\xebinmcs\x021";

	fprintf(stdout, "%s\n", magic);

	return 0;
}
