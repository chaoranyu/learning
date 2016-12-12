#include <stdio.h>
/* 统计输入的行数*/
main ( )
{
	long c, nl;
	nl = 0;
//	while ( (c = getchar ( ) ) != EOF )
//		if ( c =='\n' )
//			++nl;
	while ( (c = getchar ( ) ) != EOF ) {
		putchar(c);
		if ( c =='\n' )
			++nl;
	}
	printf("%ld\n", nl);
}
