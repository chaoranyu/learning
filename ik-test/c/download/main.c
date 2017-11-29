#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	char command_str[1024];
	char ip_host[32] = { "10.0.5.5" };
	char username[128] = { "root" };
	char password[128] = { "ufo" };
	char src_pathname[256] = { "up_scp.exp" };
	char dst_path[256] = { "/home/" };

	sprintf(command_str, "up_scp.exp %s %s %s %s %s > /dev/null 2>&1",
			ip_host, username, password, src_pathname, dst_path);

	printf("%s\n", command_str);

	int rt_value = system(command_str);

	if((0 != rt_value && rt_value != -1) || (rt_value == -1 && errno != ECHILD)) {
		printf("Failed, rt_value = %d!\n\n", rt_value);
		return 1;         
	} 

	printf("Done, rt_value = %d!\n\n", rt_value);

	return 0;
}
