#ifndef __PERSON_H__
#define __PERSON_H__

typedef void * HPERSON;

HPERSON person_create(char *name, int age);
void person_display(const HPERSON p);
void person_delete(HPERSON p);

#endif /* __PERSON_H__ */
