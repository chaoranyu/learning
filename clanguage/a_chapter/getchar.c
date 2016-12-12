#include <stdio.h>
/* 用于将输入复制到输出的程序；第2个版本*/
main ( )
{
	int c;
	while ( (c = getchar ( ) ) != EOF )
		putchar ( c );
}
