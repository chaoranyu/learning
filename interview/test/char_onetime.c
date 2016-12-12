#include <stdio.h>
#include <stdlib.h>


int reverse_str(const char *input, char *output);

int main()
{
	char *input = "abcbab";
	char *output = (char *)malloc(sizeof(char));

	printf("%s\n", input);
	int is_succeed = reverse_str(input, output);
	if (is_succeed == 0) 
		printf("%s\n", output);
	else
		printf("error\n");

	return 0;
}

int reverse_str(const char *input, char *output)
{
	if (!input || !output)
		return -1;

	int ascii[256] = {0};
	int i = 0;
	char c;
	while ((c = *input++) != '\0') {
		if (ascii[c]) {
			continue;
		} else {
			ascii[c] = 1;
			*output++ = c;
		}
	}

	return 0;
}
