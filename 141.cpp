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
    bool hasCycle(ListNode *head) {
        if(head == 0 || head->next == 0)
            return false;
        if(head->next == head)
            return true;
        
        ListNode* s = head;
        ListNode* f = head->next;
        while(f != 0 && s != 0){
            if(s == f)
                return true;
            s = s->next;
            if(f->next == 0)
                return false;
            f = f->next->next;
        }
        return false;
    }
};
