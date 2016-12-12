#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>	/* for atof() */

#define	MAXVAL	100	/* maximum depth of val stack */

void push(double);
double pop(void);

#endif // __STACK_H__
