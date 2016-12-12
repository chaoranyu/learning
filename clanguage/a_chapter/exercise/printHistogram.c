#include <stdio.h>
#define LENGTH 12
#define IN 1 /* 在单词内*/
#define OUT 0 /* 在单词外*/
/* 统计各个数字、空白字符及其他字符分别出现的次数*/
main ( )
{
	int c, i, j, nc, state;
	nc = 0;
	state = OUT;
	int ndigit[LENGTH];

	for ( i =0; i < LENGTH; ++i )
		ndigit[i] = 0;
	while ( ( c = getchar() ) != EOF ) {
		if ( c != ' ' && c != '\n' && c != '\t' ) {
		    ++nc;
		}
		else {
			if ( nc > 0 && nc < LENGTH )
				++ndigit[nc-1];
			else if ( nc > LENGTH ) {
				printf("\nError! The input word is too long\n");
				break;
			}
			nc = 0;
		}

	}

	printf( "result shows below:\n" );
	for ( i =0; i < LENGTH; ++i ) {
		printf("%2d |", i+1 );
		for ( j = 0; j < ndigit[i]; j++ ) {
			printf( "*" );
		}
		printf( "\n" );
	}
	printf("   +--------------------------\n");
}
