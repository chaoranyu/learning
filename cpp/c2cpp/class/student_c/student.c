#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

typedef struct
{
	char *name;
	int age;
	struct operations *ops;
} person_t;

struct operations
{
	void (*display)(const HPERSON);
};

static void p_display(const HPERSON p)
{
	printf("<<<<< display person infomation >>>>>\n");
	printf(" Name: %s\n Age: %d\n", ((person_t *)p)->name, ((person_t *)p)->age);
}

static struct operations person_ops = { p_display };

HPERSON person_create(char *name, int age)
{
	printf("create person\n");
	person_t *p = malloc(sizeof(person_t));
	p->name = malloc(strlen(name)+1);
	p->ops = &person_ops;

	strcpy(p->name, name);
	p->age = age;
	return p;
}

void person_delete(HPERSON p)
{
	printf("delete person\n");
	free(((person_t *)p)->name);
	free(p);
}

typedef struct
{
	person_t person;
	int score;
} student_t;

static void s_display(const HSTUDENT s)
{
	printf("<<<<< display student infomation >>>>>\n");
	printf(" Name: %s\n Age: %d\n Score: %d\n",
		   	((person_t *)s)->name, ((person_t *)s)->age, ((student_t *)s)->score);
}

static struct operations student_ops = { s_display };

HSTUDENT student_create(char *name, int age, int score)
{
	printf("create student\n");
	student_t *s = malloc(sizeof(student_t));
	((person_t *)s)->name = malloc(strlen(name)+1);
	((person_t *)s)->ops = &student_ops;

	strcpy(((person_t *)s)->name, name);
	((person_t *)s)->age = age;
	s->score = score;
	return s;
}

void student_delete(HSTUDENT s)
{
	printf("delete student\n");
	free(((person_t *)s)->name);
	free(s);
}

void display(HPERSON p)
{
	((person_t *)p)->ops->display(p);
}
