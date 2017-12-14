/* Compile: gcc test.c -l sqlite3 */
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("sample.db", &db);

    if ( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_close(db);
    exit(EXIT_SUCCESS);
}
