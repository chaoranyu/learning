#include <stdio.h>
#include <string.h>

int main()
{
    int len, nel;
    //char query[] ="username=appleboy&&&&password=123456&action=delete";
    char query[] ="username=spaceboy    password=123456 action=create";
    char *q, *name, *value;

    /* Parse into individual assignments */
    q = query;
    fprintf(stdout, "CGI[query string] : %s\n", query);
    len = strlen(query);
    nel = 0;
    //while (strsep(&q, "&"))
    while (strsep(&q, " "))
        nel++;
    fprintf(stdout, "CGI[nel string] : %d\n\n", nel);

    for (q = query; q < (query + len);) {
        value = name = q;

        /* Skip to next assignment */
        fprintf(stdout, "CGI[str  ] : %s\n", q);
        fprintf(stdout, "CGI[len  ] : %zu\n", strlen(q));
        fprintf(stdout, "CGI[addr ] : %p\n", q);

        for (q += strlen(q); q < (query +len) && !*q; q++);

        /* Assign variable */
        name = strsep(&value,"=");
        fprintf(stdout, "CGI[name ] : %s\n", name);
        fprintf(stdout, "CGI[value] : %s\n\n", value);
    }

    return 0;
}
