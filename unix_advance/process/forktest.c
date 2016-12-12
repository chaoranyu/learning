#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	printf("%d\n", getpid());
	fork();
	fork();
	fork();
	printf("%d\n", getpid());
}
