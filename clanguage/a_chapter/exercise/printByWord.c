#include <stdio.h>
#define IN 1 /* 在单词内*/
#define OUT 0 /* 在单词外*/
/* 统计输入的行数、单词数与字符数*/
main ( )
{
	int c;

	while ( (c = getchar ( ) ) != EOF ) {
		putchar(c);
		if ( c == ' ' || c == '\n' || c == '\t' )
			putchar('\n');
	}
}
