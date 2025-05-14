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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* prev = new ListNode();
        prev->next = head;
        ListNode* curr = head;
        ListNode* res = prev;
        while(curr && curr->next){
            int currVal = curr->val; 
            if(curr->next->val == currVal){
                while(curr && curr->val == currVal){
                    curr = curr->next;
                }
                prev->next = curr;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return res->next;
    }
};