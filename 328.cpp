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
    ListNode* oddEvenList(ListNode* l) {
        if(l == 0 || l->next ==0 || l->next->next == 0)
          return l;

        ListNode* e_head = l->next;
        ListNode* to = l;
        ListNode* te = e_head;
        while(te!=0 && te->next != 0){
          to->next = te->next;
          te->next = to->next->next;
          to = to->next;
          te = te->next;
        }
        to->next = e_head;
        return l;
    }
};
