#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		//ListNode *walk = head;

		if (head == nullptr || head->next == nullptr) return head;
		ListNode *p = head->next, *prep = head;

		while (p != nullptr) {
			if (prep->val == p->val) {
				p = p->next;
				prep->next = p;
			}
			else {
				prep = p;
				p = p->next;
			}
		}

		return head;
	}
};

int main(int argc, char *argv[])
{
	ListNode *head, *p;
	p = head = new ListNode(1);
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;

    ListNode *walk = head;
	while (walk != nullptr) {
		std::cout << walk->val << " ";
		walk = walk->next;
	}
	std::cout << "\n";

	Solution s;
	s.deleteDuplicates(head);

    walk = head;
	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << "\n";

	return 0;
}
