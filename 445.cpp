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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        int carry = 0;
        std::stack<int> s1;
        std::stack<int> s2;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1){
            s1.push(t1->val);
            t1 = t1->next;
        }
        
        while(t2){
            s2.push(t2->val);
            t2 = t2->next;
        }
        ListNode* tail = nullptr;
        int a, b;
        while(!s1.empty() || !s2.empty()){
            a = 0; b = 0;
            if(!s1.empty()){
                a = s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                b = s2.top();
                s2.pop();
            }
            int sum = a + b + carry;
            int r = sum%10;
            carry = sum/10;
            ListNode* t = new ListNode(r);
            t->next = tail;
            tail = t;
        }
        if(carry){
            ListNode* t = new ListNode(carry);
            t->next = tail;
            tail = t;
        }
        return tail;
    }

};
