#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
public:
	Person(const char *name, int age);
	~Person();
	virtual void display() const;
protected:
	char *name;
	int age;
};

#endif // __PERSON_H__
