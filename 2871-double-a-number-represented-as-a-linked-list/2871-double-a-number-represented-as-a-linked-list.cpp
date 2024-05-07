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
    int foo(ListNode* node){
        if(!node) return 0;
        int rem = foo(node->next);
        int val = node->val;
        node->val = (val*2 + rem)%10;
        return (val*2 + rem)/10;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = new ListNode(0, head);
        int rem = foo(head);
        if(rem) return new ListNode(rem, head);
        return head;
    }
};