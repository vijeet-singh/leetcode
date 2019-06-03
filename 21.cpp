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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        
	ListNode* temp = nullptr;
    ListNode* head = nullptr;
        
	if(l1->val < l2->val){
		head = l1;
		temp = l1;
		l1 = l1->next;
	}
	else{
		head = l2;
		temp = l2;
		l2 = l2->next;
	}
        
	while(l1 && l2){
		if(l1->val < l2->val){
			temp->next = l1;
			temp = temp->next;
			l1 = l1->next;
		}
		else{
			temp->next = l2;
			temp = temp->next;
			l2 = l2->next;
		}
	}
        
	if(l1)
		temp->next = l1;
	else
		temp->next = l2;
        
	return head;
    }
};
