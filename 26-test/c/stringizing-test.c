#include <stdio.h>

#define WARN_IF(EXP) \
do { if (EXP) \
        fprintf (stderr, "Warning: " #EXP "\n"); } \
while (0)

#define xstr(s) str(s)
#define str(s) #s
#define foo 4

#define CSI_START                      "\033["
#define CSI_END                        "\033[0m"
#define F_CYAN                         "36;"
#define B_NULL
#define S_NORMAL                       "22m"
#define SYSLOG_COLOR_INFO              (F_CYAN B_NULL S_NORMAL)

#ifndef print_title
#define print_title(fmt, args...)                           \
    do {                                                    \
        fprintf(stdout, "%s%s[%s:%d] " fmt "%s",            \
                CSI_START, SYSLOG_COLOR_INFO,               \
                __func__, __LINE__, ##args, CSI_END);       \
    } while (0)
#endif

//typedef void (function_t) (void);

struct command
{
    char *name;
    void (*function) (void);
    //function_t *function;
};

#define COMMAND(NAME)  { #NAME, NAME ## _command }

void quit_command(void);
void help_command(void);
void test_command(void);

struct command commands[] =
{
	COMMAND (quit),
	COMMAND (help),
	COMMAND (test)
};

int main()
{
    printf("macro test:\n");
    print_title("macro test:\n");
    fprintf(stderr, "666\n");

    // Stringizing
	int x = 0;
	WARN_IF(x == 0);

	printf("%s\n", str(foo));
	printf("%s\n", xstr(foo));

    // Concatenation
	int i;
    for (i = 0; i < sizeof(commands)/sizeof(commands[0]); i++)
    {
        printf("excute %s\n", commands[i].name);
        commands[i].function();
    }

	return 0;
}

void quit_command(void)
{
	printf("quit\n");
}

void help_command(void)
{
	printf("help\n");
}

void test_command(void)
{
	printf("test\n");
}

