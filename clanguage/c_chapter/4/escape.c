#include <stdio.h>

void escape(char s[], char t[])
{
	int i, j;
	i = j = 0;

	while ( t[i] )
	{
		switch ( t[i] ) {
		case '\t':
			s[j++] = '\\';
			s[j] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j] = 'n';
			break;
		case '\a':
			s[j++] = '\\';
			s[j] = 'a';
			break;
		case '\b':
			s[j++] = '\\';
			s[j] = 'b';
			break;
		case '\f':
			s[j++] = '\\';
			s[j] = 'f';
			break;
		case '\r':
			s[j++] = '\\';
			s[j] = 'r';
			break;
		case '\v':
			s[j++] = '\\';
			s[j] = 'v';
			break;
		case '\\':
			s[j++] = '\\';
			s[j] = '\\';
			break;
		case '\"':
			s[j++] = '\\';
			s[j] = '"';
			break;
		default:
			s[j] = t[i];
			break;
		}
		++i;
		++j;
	}
	s[j] = t[i];
}

void unescape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (t[i] != '\0')
	{
		switch (t[i]) {
		case '\\':
			switch (t[++i])
			{
				case 't':
					s[j] = '\t';
					break;
				case 'n':
					s[j] = '\n';
					break;
				case 'a':
					s[j] = '\a';
					break;
				case 'b':
					s[j] = '\b';
					break;
				case 'f':
					s[j] = '\f';
					break;
				case 'r':
					s[j] = '\r';
					break;
				case 'v':
					s[j] = '\v';
					break;
				case '\\':
					s[j] = '\\';
					break;
				case '\"':
					s[j] = '\"';
					break;
				default:
					s[j++] = '\\';
					s[j] = t[i];
					break;
			}
			break;
		default:
			s[j] = t[i];
			break;
		}
		++i;
		++j;
	}
	s[j] = t[i];
}

int main()
{
	char s[256] = "";
	char t[256] = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";

	printf("Original string:\n%s\n", t);

	escape(s, t);
	printf("Escaped string:\n%s\n", s);

	unescape(t, s);
	printf("Unescaped string:\n%s\n", t);

	return 0;
}
