// main.cpp

#include "List.h"
#include <iostream>

int main(int argc, char* argv[])
{
	ListNode *entry = CreateList();
	OutputList();

    std::cout << "delete: ";
    int val;
    std::cin >> val;
    if (val > MAX) {
        std::cerr << "bad input!\n";
        return -1;
    }
	while (entry != nullptr && entry->val != val)
		entry = entry->next;

	remove_list_entry(entry);
	OutputList();

	return 0;
}
