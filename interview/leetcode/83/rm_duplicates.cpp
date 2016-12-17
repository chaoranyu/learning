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
            } else {
                prep = p;
                p = p->next;
            }
        }
        
        return head;
    }
};

// my ugly test code
int main(int argc, char *argv[])
{
	ListNode *head;
	ListNode *p = head, *q;
	head = p = new ListNode(1);
	q = new ListNode(1);
	p->next = q;
	p = p->next;
	q = new ListNode(4);
	p->next = q;
	p = p->next;
	q = new ListNode(4);
	p->next = q;

	q = head;
	while (q != nullptr) {
		std::cout << q->val << " ";
		q = q->next;
	}
	std::cout << "\n";

	Solution s;
	s.deleteDuplicates(head);

	q = head;
	while (q != nullptr) {
		std::cout << q->val << " ";
		q = q->next;
	}
	std::cout << "\n";

	return 0;
}
