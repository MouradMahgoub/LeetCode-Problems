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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head; 
        int len=1; ListNode *oldTail = head;
        while(oldTail->next != NULL){
            oldTail = oldTail->next;
            len++;
        }
        oldTail->next = head;
        k %= len;
        ListNode* newTail = head;
        for(int i=0; i<len-k-1; i++)
            newTail = newTail->next;
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};