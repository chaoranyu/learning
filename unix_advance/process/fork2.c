#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	int pid;
	/* fork another process */
	pid = fork();
	if (pid < 0) { // error occurred
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if (pid == 0) { // child process
		execlp("/bin/ls", "ls", "-l", NULL);
		printf("pid of child process is %d\n", getpid());
	}
	else { // parent process
		/* parent will wait for the child to complete */
		wait(NULL);
		printf("Child Complete\n");
		printf("pid of parent process is %d\n", getpid());
		exit(0);
	}
}
