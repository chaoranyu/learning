/* person.h */

struct s_person;

typedef Person struct s_person;

Person* new_Person(char* name);
void delete_Person(Person* person);

void Person_setName(Person* person, char* name);
char* Person_getName(Person* person);
