#include "true_false.h"

void tt(){
	char *s = (char *)malloc(10 * sizeof(char));
	char *d = (char *)malloc(10 * sizeof(char));
	strlen(s);
	strncat(s, d, strlen(s));
}

void test26()
{
	LIST_t list1;
	LIST2_t list2;
	LIST3_t list3;

	cout << sizeof(LIST_t) << endl;
	cout << sizeof(LIST2_t) << endl;
	cout << sizeof(LIST3_t) << endl;
}
