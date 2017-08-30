/* person.c */
#include <string.h>

#include "person.h"

struct s_person {
    char* name;
};

Person* new_Person(char* name) {
    Person* object = (Person*)malloc(sizeof(struct s_person));
    // duplicate the string for more security, otherwise constructor
    // could manipulate the "private" string after construction.
    object->name = strdup(name);
    return object;
}

void delete_Person(Person* person) {
    // some implementations pass a Person** to set the reference to 0
    // this implementation requires that the caller sets his own references to 0
    free(person->name);
    free(person);
}

void Person_setName(Person* person, char* name) {
    // free the old
    free(person->name);
    // duplicate the new to provide "out of simulated class" modification by malicious 
    // name setter.
    person->name = strdup(name);
}

char* Person_getName(Person* person) {
    // must return a copy, otherwise one can manipulate name
    // from reference provided by Person_getName(...);
    return strdup(person->name);
}

