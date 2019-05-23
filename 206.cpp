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
    ListNode* reverseList(ListNode* head) {
        if(head == 0 || head->next == 0)
            return head;
        
        ListNode* t1 = 0;  //1,2,3 are timestamps of traversing pointers
        ListNode* t2 = head;
        ListNode* t3;
        
        while(t2 != 0){  //reversing the links iteratively
            t3 = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = t3;            
        }
        head = t1;
        return head;
    }
};
