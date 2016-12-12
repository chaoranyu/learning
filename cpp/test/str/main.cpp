#include <stdio.h>
#include <string.h>

typedef struct TitleInfo_t
{
	char c[8];         // 节目名
	int n;    // 时长（单位分钟）
}TitleInfo;
typedef struct TitleInfo2_t
{
	char *c;         // 节目名
	int n;    // 时长（单位分钟）
}TitleInfo2;


int main()
{
	char* s1 = "12";
	char* s2 = "13";
	printf("%d\n", strcmp(s1, s2));

	TitleInfo info;

	//strcpy();
	strcpy(info.c, "sss");
	info.n = 4;

	printf("%s\n", info.c);
	printf("%d\n", info.n);

	TitleInfo info2;

	//strcpy();
	strcpy(info2.c, info.c);
	info2.n = 3;

	printf("%s\n", info.c);
	printf("%d\n", info.n);
/*
	strcpy(info.c, "22");

	printf("%s\n", info.c);
	printf("%d\n", info.n);

*/
	return 0;
}
