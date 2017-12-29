#include <stdio.h>

int int_array[5];
double double_array[10];
char char_array[] = {'a', 'b', 'c', 'd'};

int main ()
{
    const char * format = "The %s array has %d bytes and %d elements.\n";

    printf (format, "int",
            sizeof (int_array), sizeof (int_array) / sizeof (int));
    printf (format, "double",
            sizeof (double_array), sizeof (double_array) / sizeof (double));

    /* This method works even when the size of the array is not
       specified in the initializer. */
    printf (format, "char",
            sizeof (char_array), sizeof (char_array) / sizeof (char));

    return 0;
}
