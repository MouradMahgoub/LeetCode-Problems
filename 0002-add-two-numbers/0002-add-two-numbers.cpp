/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while(l1 || l2){
            int temp = curr->val;
            if(l1) temp += l1->val;
            if(l2) temp += l2->val;
            int val = temp%10;
            int rem = temp/10;
            curr->val = val;
            curr->next = new ListNode(rem);
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            if(l1 || l2) curr  = curr->next;
        }
        if(curr->next->val == 0) curr->next = NULL;
        return res;
    }
};


        // ListNode* dummy = new ListNode(0);
        // ListNode* temp = dummy;
        // int carry = 0;
        // while(l1 || l2 || carry){
        //     int d1 = l1 ? l1->val : 0;
        //     int d2 = l2 ? l2->val : 0;
        //     int res = d1 + d2 + carry;
        //     temp->next = new ListNode(res%10);
        //     carry = res/10;
        //     temp = temp->next;
        //     l1 = l1 ? l1->next : NULL;
        //     l2 = l2 ? l2->next : NULL;
        // }
        // return dummy->next;