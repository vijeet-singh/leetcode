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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int, vector<int>, greater<int> > pq;
        
        for(int i = 0; i < lists.size(); i++){
            ListNode* head_t = lists[i];
            while(head_t){
                pq.push(head_t->val);
                head_t = head_t->next;
            }
        }
        
        if(!pq.empty()){
        ListNode* head = new ListNode(pq.top());
        pq.pop();
        ListNode* temp = head;
        while(!pq.empty()){
            ListNode* curr = new ListNode(pq.top());
            pq.pop();
            temp->next = curr;
            temp = curr;
        }
        temp->next = nullptr;
        return head;
        }
        
        return nullptr;
    }
};
