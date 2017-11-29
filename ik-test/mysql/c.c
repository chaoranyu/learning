#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (mysql_library_init(0, NULL, NULL)) {
        fprintf(stderr, "could not initialize MySQL library\n");
        exit(1);
    }

    MYSQL *mysql;
    char *query_string;

    /* Use any MySQL API functions here */
    MYSQL_RES *result;
    unsigned int num_fields;
    unsigned int num_rows;
    if (mysql_query(&mysql,query_string))
    {
        // error
    }
    else // query succeeded, process any data returned by it
    {
        result = mysql_store_result(&mysql);
        if (result) // there are rows
        {
            num_fields = mysql_num_fields(result);
            // retrieve rows, then call mysql_free_result(result)
        }
        else // mysql_store_result() returned nothing; should it have?
        {
            if (mysql_errno(&mysql))
            {
                fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
            }
            else if (mysql_field_count(&mysql) == 0)
            {
                // query does not return data
                // (it was not a SELECT)
                num_rows = mysql_affected_rows(&mysql);
            }
        }
    }

    mysql_library_end();
    return EXIT_SUCCESS;
}
