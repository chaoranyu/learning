#include "minprintf.c"

void main()
{
	int year = 2014, month = 8, date = 2;
	char *string = "Double Seventh Festival";

	minprintf("%d/%d/%d, %s\n", year, month, date, string);
}
