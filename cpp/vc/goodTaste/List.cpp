// List.cpp
#include "List.h"
#include <iostream>

static ListNode *head = nullptr;

#if 0
void remove_list_entry(ListNode *entry)
{
	ListNode *prev = nullptr;
	ListNode *walk = head;

	// walk the list

	while (walk != entry)
	{
		prev = walk;
		walk = walk->next;
	}

	// Remove the entry bye updating the
	// head or the previous entry

	if (!prev)
		head = entry->next;
	else
		prev->next = entry->next;
}
#else
void remove_list_entry(ListNode *entry)
{
	// The "indirect" pointer  points to the
	// *address* of the thing we'll update

	ListNode **indirect = &head;

	// Walk the list, looking for the thing that
	// points to the entry we want to remove

	while ((*indirect) != entry)
		indirect = &(*indirect)->next;

	// .. and just remove it

	*indirect = entry->next;
}
#endif

ListNode* CreateList()
{
	head = new ListNode(0);
	ListNode *walk = head;

	for (int i = 1; i < MAX; i++)
	{
		walk->next = new ListNode(i);
		walk = walk->next;
	}
    return head;
}

void OutputList()
{
	ListNode *walk = head;
	while (walk != nullptr)
	{
        std::cout << walk->val << "   ";
		walk = walk->next;
	}
    std::cout << std::endl;
}
