#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>
#include <ctype.h>

#define	NUMBER	'0'	/* signal that a number was found */
#define BUFSIZE	100

static int getch(void);
static void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]);

#endif // __IO_H__
