#include <string.h>

class Stack
{
public:
	Stack(char * s = NULL) {if(s != NULL) {str = new char[strlen(s)+1]; strcpy(str, s);}}
	~Stack() {delete str; str = NULL;}

	const char * getString(void) { return str; }

private:
	char * str;
};
