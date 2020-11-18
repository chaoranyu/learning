#include <stdio.h>

int function(void) {
	static int i, state = 0;
	switch (state) {
		case 0: goto LABEL0;
		case 1: goto LABEL1;
	}
LABEL0: /* start of function */
	for (i = 0; i < 10; i++) {
		state = 1; /* so we will come back to LABEL1 */
		return i;
LABEL1:; /* resume control straight after the return */
	}
}

int function2(void) {
	static int i, state = 0;
	switch (state) {
		case 0: /* start of function */
			for (i = 0; i < 10; i++) {
				state = 1; /* so we will come back to "case 1" */
				return i;
				case 1:; /* resume control straight after the return */
			}
	}
}

int function3(void) {
	static int i, state = 0;
	switch (state) {
		case 0: /* start of function */
			for (i = 0; i < 10; i++) {
				state = __LINE__ + 2; /* so we will come back to "case __LINE__" */
				return i;
				case __LINE__:; /* resume control straight after the return */
			}
	}
}

#define Begin() static int state=0; switch(state) { case 0:
#define Yield(x) do { state=__LINE__; return x; case __LINE__:; } while (0)
#define End() }
int function4(void) {
	static int i;
	Begin();
	for (i = 0; i < 10; i++)
		Yield(i);
	End();
}

typedef int (*func)(void);

void print_ten(func f)
{
	int i;
	for (i = 0; i < 10; i++)
		printf("%d  ", f());
	printf("\n");

	return;
}

int main()
{
	// printf("%d  ", function());
	// printf("%d  ", function());
	// printf("%d  ", function());
	// printf("%d  \n", function());

	print_ten(function);
	print_ten(function2);
	print_ten(function2);
	print_ten(function3);
	print_ten(function4);

	return 0;
}
