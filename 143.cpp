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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;
        std::stack<ListNode*> s;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while((fast != nullptr) && (fast->next != nullptr)){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* tail = slow;
        slow = slow->next;
        
        while(slow != nullptr){
            s.push(slow);
            slow = slow->next;
        }
        
        ListNode* t = head;
        ListNode* aux;
    while(!s.empty()){
        aux = t->next;
        t->next = s.top();
        //aux = s.top();
        t = aux;
        s.top()->next = t;
        s.pop();
    }
        
        tail->next = nullptr;
    }
};
