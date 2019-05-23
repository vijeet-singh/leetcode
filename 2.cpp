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
        ListNode* t1 = l1;
	ListNode* t2 = l2;
	int a,b,c = 0;
	bool chk = true;
	ListNode* la(0);
    ListNode* t3(0);
    ListNode* t4(0);
	while(t1 != 0 || t2 != 0){
	a = 0;
	b = 0;
		if(t1 != 0){
			a = t1->val;
			t1 = t1->next;
		}
		if(t2 != 0){
			b = t2->val;
			t2 = t2->next;
		}
		int sum = a+b+c;
		c = sum/10;
		int res = sum%10;
		if(chk){
			la = new ListNode(res);
			t3 = la;
			t3->next = 0;
			chk = false;
		}
		
		else{
			t4= new ListNode(res);
			t3->next = t4;
			t4->next = 0;
			t3 = t4;
		}
	}
	if(c){
		t4 = new ListNode(c);
		t3->next = t4;
		t4->next = 0;
	}
	return la;
    }
};
