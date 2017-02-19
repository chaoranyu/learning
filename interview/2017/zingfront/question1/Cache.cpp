// Cache.cpp
#include "Cache.h"

bool Cache::add()
{
    if (m_num >= 100) return false;

	item *new_item = new item;
	new_item->id = ++m_id;
	new_item->age = 0;
	new_item->next = nullptr;

	if (m_num == 0) {
			head = new_item;
			m_num++;
			return true;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, m_num+1);
	int pos = dis(gen);

	if (pos == 0) {
		new_item->next = head;
		head = new_item;
	}
	else {
		item *p = head, *prep = head;
		for (int i = 0; i < pos && p != nullptr; i++)
		{
			prep = p;
			p = p->next;
		}
		new_item->next = p;
		prep->next = new_item;
	}
	m_num++;

	return true;
}

bool Cache::del()
{
	if (head == nullptr) return false;

	item *p = head, *prep = nullptr;
	if (m_num >= 100 || p->age > 10) {
		head = p->next;
		delete p;
	}
	else
	{
		while (p != nullptr && p->age <= 10)
		{
			prep = p;
			p = p->next;
		}

		if (p == nullptr) {
			return false;
		}
		else {
			prep->next = p->next;
			delete p;
		}
	}

	m_num--;
	return true;
}

void Cache::pass_one_second()
{
	item *walk = head;
	while (walk != nullptr)
	{
		walk->age++;
		walk = walk->next;
	}
}

void Cache::output_items()
{
    int count = 0;
	item *walk = head;
	while (walk != nullptr)
	{
		std::cout << walk->id << "," << walk->age << "  ";
		walk = walk->next;
        count++;
	}
	std::cout << "[" << count << " items]" << std::endl;
}
