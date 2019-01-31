/* touch /proc/self/coredump_filter */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;

	//fd = open ("/proc/self/coredump_filter", O_WRONLY);
	fd = open ("/root/coredump_filter", O_WRONLY);
	if (fd >= 0)
	{
		if (write (fd, "0x6f\n", 5) != 5)
			printf("coredump filter write failed!\n");
		close (fd);
	}
	else
		printf("couldn't open /root/coredump_filter.\n");

	return 0;
}
