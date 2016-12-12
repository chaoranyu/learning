#ifndef __STUDENT_H__
#define __STUDENT_H__

typedef void * HPERSON;
typedef void * HSTUDENT;

static void p_display(const HPERSON p);
HPERSON person_create(char *name, int age);
void person_delete(HPERSON p);

static void s_display(const HSTUDENT s);
HSTUDENT student_create(char *name, int age, int score);
void student_delete(HSTUDENT s);
void display(HPERSON p);

#endif /* __STUDENT_H__ */
