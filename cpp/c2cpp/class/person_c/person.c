#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

typedef struct
{
	char *name;
	int age;
} person_t;

HPERSON person_create(char *name, int age)
{
	printf("create person\n");
	person_t *p = malloc(sizeof(person_t));
	p->name = malloc(strlen(name)+1);

	strcpy(p->name, name);
	p->age = age;
	return p;
}

void person_display(const HPERSON p)
{
	printf("<<<<< display person infomation >>>>>\n");
	printf(" Name: %s\n Age: %d\n", ((person_t *)p)->name, ((person_t *)p)->age);
}

void person_delete(HPERSON p)
{
	printf("delete person\n");
	free(((person_t *)p)->name);
	free(p);
}
