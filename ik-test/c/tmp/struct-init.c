#include <stdio.h>

typedef struct {
    char *full;
    char *shortname;
} algo_name_t;

int main()
{
    const algo_name_t names[2] = {
        { "none", "n"},
        { "httpfree", "http"}
    };

    printf("%s\n", names[0].full);
    printf("%s\n", names[0].shortname);
    printf("%s\n", names[1].full);
    printf("%s\n", names[1].shortname);

    return 0;
}
