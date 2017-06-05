#include <stdio.h>
#include <string.h>

int main()
{
    //char view_name[] = "ik-ddos-zonE";
    char view_name[] = "ik-ddos-zone";

	//if(strncmp(view_name, "ik-ddos-zone", 12))
	if(strncmp(view_name, "ik-ddos-zone", strlen("ik-ddos-zone")))
	{
		printf("view para error! view :%s\n", view_name);

        return 1;
	}

    printf("view para right! view :%s\n", view_name);

    return 0;
}
