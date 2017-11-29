#include <stdio.h>
#include <string.h>

int main()
{
    //char view_name[] = "ufo-test-zonE";
    char view_name[] = "ufo-test-zone";

	//if(strncmp(view_name, "ufo-test-zone", 12))
	if(strncmp(view_name, "ufo-test-zone", strlen("ufo-test-zone")))
	{
		printf("view para error! view :%s\n", view_name);

        return 1;
	}

    printf("view para right! view :%s\n", view_name);

    return 0;
}
