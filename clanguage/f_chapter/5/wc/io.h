#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */

static int getch(void); /* get a (possibly pushed-back) character */
static void ungetch(int c); /* push character back on input */

int getword(char *word, int lim);
