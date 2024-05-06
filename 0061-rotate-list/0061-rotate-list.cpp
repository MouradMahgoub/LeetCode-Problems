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
    int listSize (ListNode* head) {
        if(!head) return 0;
        ListNode* curr = head;
        int n=1;
        while(curr->next != NULL){
            curr = curr->next;
            n++;
        }
        curr->next = head;
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head; 
        int n = listSize(head);
        k %= n;
        ListNode* curr = head;
        for(int i=0; i<n-k-1; i++)
            curr = curr->next;
        ListNode* newTail = curr; 
        ListNode* newHead = curr->next;
        newTail->next = NULL;
        return newHead;
    }
};