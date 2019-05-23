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
    void deleteNode(ListNode* node) {
        ListNode* t;
	node->val = node->next->val;
        t = node->next;
        node->next = node->next->next;
	t->next = 0;
        delete t;
    }
};
