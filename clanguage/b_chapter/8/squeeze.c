#include <stdio.h>

int squeeze(char s[], char t[]);

void main()
{
	char s[] = "A hello,B worldC!";
	char t[] = "ABC ";
	squeeze(s, t);
	printf("%s\n", s);
}


int squeeze(char s[], char t[])
{
	int i = 0, j, k;
	while (t[i] != '\0')
	{
		for (j = k = 0; s[j] != '\0'; j++)
		{
			if (s[j] != t[i])
				s[k++] = s[j];
		}
		s[k] = '\0';
		i++;
	}

	return -1;
}
