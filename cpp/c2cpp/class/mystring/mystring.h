#include <iostream>
using namespace std;

class MyString
{
	friend ostream &operator<<(ostream &, const MyString &);
	friend MyString operator+(const MyString &, const MyString &);
public:
	MyString(const char *);
	MyString(const MyString &);
	~MyString(void);
	MyString &operator=(const MyString &other);
	int Length(void) const;
	bool IsEmpty(void) const;
private:
	char *data;
	int len;
};
