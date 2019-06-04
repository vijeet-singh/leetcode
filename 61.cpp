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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* t = head;
        int count = 0;
        while(t){
            count++;
            t = t->next;
        }
        int shift = k%count;
        if(shift == 0)
            return head;
        
        t = head;
        ListNode* tail = head;
        while(shift--){
            t = t->next;
        }
        while(t->next){
            t = t->next;
            tail = tail->next;
        }
        
        t->next = head;
        head = tail->next;
        tail->next = nullptr;
        
        return head;
    }
};
