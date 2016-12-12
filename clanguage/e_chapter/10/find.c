#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline2(char *line, int max);
int getline3(char *line, int max);

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (getline3(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%3ld ", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}

int getline2(char s[], int lim)
{
	int i, c;

	for (i = 0; i < lim-1 && ((c = getchar()) != '\n' && c != EOF); i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

int getline3(char *line, int max)
{
	int c;
	char *ps = line;

	while (--max > 0 && (c = getchar()) != '\n' && c != EOF)
		*ps++ = c;
	if (c == '\n')
		*ps++ = c;
	*ps = '\0';
	return ps - line;
}
