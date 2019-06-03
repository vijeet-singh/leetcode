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
    ListNode *detectCycle(ListNode *head) {
        if(head == 0 || head->next == 0)
            return nullptr;
        std::unordered_set<ListNode*> pool;
        ListNode* trav = head;
        while(trav){
            if(pool.find(trav) == pool.end())
                pool.insert(trav);
            else
                return trav;
            trav = trav->next;
        }
        return nullptr;
    }
};
