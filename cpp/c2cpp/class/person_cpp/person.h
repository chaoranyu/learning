#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
public:
	Person(const char *name, int age);
	~Person();
	void display() const;
private:
	char *name;
	int age;
};

#endif // __PERSON_H__
