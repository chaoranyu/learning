// Cache.h
#include <iostream>
#include <random>

struct item
{
	int id;
	int age;
	item *next;
};

class Cache
{
public:
	bool add();
	bool del();
	void pass_one_second();
	void output_items();

private:
	const int MAX_CAPACITY = 100;
	item* head = nullptr;
	int m_num = 0;
	int m_id = 0;
};
