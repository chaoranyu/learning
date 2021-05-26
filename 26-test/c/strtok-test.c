#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define show_info(x)            \
do {                            \
	if (x)                      \
        printf("%s|", x);      \
    else                        \
        printf("<NULL>\n");    \
} while(0)

void test_strtok(void);
void test_strsep(void);

int main()
{
    test_strtok();
    test_strsep();

	return 0;
}

void test_strtok(void)
{
	const char string[] = "words separated by spaces -- and, punctuation!";
	const char delimiters[] = " .,;:!-";
	char *token, *cp;

	cp = strdupa (string);                /* Make writable copy.  */
    printf ("Splitting string \"%s\" into tokens using strtok:\n", cp);

	token = strtok (cp, delimiters);      /* token => "words" */
    show_info(token);
	token = strtok (NULL, delimiters);    /* token => "separated" */
    show_info(token);
	token = strtok (NULL, delimiters);    /* token => "by" */
    show_info(token);
	token = strtok (NULL, delimiters);    /* token => "spaces" */
    show_info(token);
	token = strtok (NULL, delimiters);    /* token => "and" */
    show_info(token);
	token = strtok (NULL, delimiters);    /* token => "punctuation" */
    show_info(token);
	token = strtok (NULL, delimiters);    /* token => NULL */
    show_info(token);
	printf("\n");
}

void test_strsep(void)
{
	const char string[] = "words separated by spaces -- and, punctuation!";
	const char delimiters[] = " .,;:!-";
	char *running;
	char *token;

	running = strdupa (string);
    printf ("Splitting string \"%s\" into tokens using stdsep:\n", running);
	
	token = strsep (&running, delimiters);    /* token => "words" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "separated" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "by" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "spaces" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "and" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "punctuation" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => "" */
    show_info(token);
	token = strsep (&running, delimiters);    /* token => NULL */
    show_info(token);
	printf("\n");
}
