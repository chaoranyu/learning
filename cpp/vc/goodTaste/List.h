// List.h

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

const int MAX = 10;
void remove_list_entry(ListNode *entry);

ListNode* CreateList();
void OutputList();
