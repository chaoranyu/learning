/* otherfile.c */
#include <stdio.h>

#include "person.h"

/* Now we can hold Person "simulated objects", but we cannot */
/* manipulate their "state" without using the C simulated object */
/* methods */

int main(int argc, char** argv) {

    Person* bob = new_Person("bob");
    printf("%s\n", Person_getName(bob));
    delete_Person(bob);
    // critical or we hold a pointer to freed memory.
    bob =  0;

    return 0;
}
