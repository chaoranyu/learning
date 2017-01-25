/* to be continued */


#include <stdio.h>

#define	FRI_NUM_MAX	1000

int itemp=0;
int times=0;

void change(int *a,int *b)
{
	itemp=*a;
	*a=*b;
	*b=itemp;
	times++;
}

void quickSort(int *a,int len)
{
	int num=0,i=0,j=len-1;
	int temp=*a;
	if(len>1)
		while(i!=j&&i<j)
		{
			for(j;j>num;j--)
			{
				if(*(a+j)>*(a+num))
				{	
					change((a+j),(a+num));
					num=j;
					break;
				}
			}
			for(i;i<num;i++)
			{
				if(*(a+i)<*(a+num))
				{
					change((a+i),(a+num));
					num=i;
					break;
				}
			}
			quickSort(a,num);
			quickSort((a+num+1),len-num-1);
		}
}

int main(int argc, char* argv[])
{
	int num;
	scanf("%d", &num );

	int K1, A1, B1, K2, A2, B2;
	scanf( "%d %d %d %d %d %d", &K1, &A1, &B1, &K2, &A2, &B2 );

	int sum = 0,countA = 0, countB = 0;
	int ValAB[FRI_NUM_MAX];

	for ( int i = 0; i < num; i++ )
	{
		int x, y;
		scanf( "%d %d", &x, &y );

		int ValA = A1 * x + B1 * y;
		int ValB = A2 * x + B2 * y;
		ValAB[i] = ValA - ValB;

		if ( 0 <= ValAB[i] )
		{
			sum += ValA;
			countA++;
		}
		else
		{
			sum += ValB;
			countB++;
		}
	}

	if ( countA == K1 )
	{
		printf( "The max happy is %d\n", sum );
		return 0;
	}

	// Sort
	quickSort( ValAB, sum );

	if ( countA > K1 )
	{
		for ( int j = 0; j < countA - K1; j++ )
		{
			sum += ValAB[j];		
		}
	}
	else
	{
		for ( int k = 0; k < countA - K1; k++ )
		{
			sum -= ValAB[num - k];
		}
	}

	printf( "The max happy is %d\n", sum );

	return 0;
}

