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
        if(head == nullptr || head->next == nullptr) return head;
        
    unordered_set<int> s;
    ListNode* t = head;
    
    while(t->next != nullptr){
        if (t->val == t->next->val){
            s.insert(t->val);	
        }
    t = t->next;	
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
//ListNode* fut = head->next;

    while(prev->next != nullptr){
        if(s.find(curr->val) != s.end()){
            ListNode* temp = curr;
            prev->next = curr->next;
            delete temp;
            curr = prev->next;
        }
        else{
            prev = prev->next;
            curr = curr->next;
        }
    }
    head = dummy->next;
    return head;
    
}
};
