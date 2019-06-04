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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int a = 0;
        int b = 0;
        while(temp1->next != nullptr){
            temp1 = temp1->next;
            a++;
        }
        while(temp2->next != nullptr){
            temp2 = temp2->next;
            b++;
        }
        if(temp1 != temp2)
            return nullptr;
        
        temp1 = headA;
        temp2 = headB;
        
        int diff = abs(a-b);
        int count = diff;
        if(a>b){
            while(count--){
                temp1 = temp1->next;
            }
        }
        if(b>a){
            count = diff;
            while(count--){
                temp2 = temp2->next;
            }
        }
            
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
        
    }
};
