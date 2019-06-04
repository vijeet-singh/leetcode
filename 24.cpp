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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
    
    ListNode* odd = head;
    ListNode* even = head->next;
    head = even;
    ListNode* temp;
    while(1){
        temp = even->next;
        even->next = odd;
        if(temp){
            if(temp->next)
                odd->next = temp->next;
            else{
                odd->next = temp;
                break;
            }
            odd = temp;
            even = temp->next;
        }
        else{
            odd->next = nullptr;
            break;
        }
//        odd->next = temp;
//        odd = odd->next;
//        if(odd) even = odd->next;
    }
    
    return head;
    }
};
