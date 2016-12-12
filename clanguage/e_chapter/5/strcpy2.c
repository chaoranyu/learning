#include <stdio.h>
#include <stddef.h>
#include <assert.h>

char * strcpy2 (char *dest, const char *src);

int main()
{
	char src1[] = "abcdefg"; 
	char dest1[10] = ""; 
	strcpy2(dest1, src1);

	char src3[] = "abcdefg"; 
	char *dest3 = src3; 
	strcpy2(dest3, src3);

	char *src2 = NULL; 
	char *dest2 = NULL; 
	strcpy2(dest2, src2);

	return 0;
}

/* Copy SRC to DEST.  */
char *
strcpy2 (char *dest, const char *src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *ret = dest;
    while ( *dest++ = *src++ );   
	return ret;
}
