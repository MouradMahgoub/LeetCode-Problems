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
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(h1 && h2){
            if(h1->val <= h2->val){
                curr->next = h1;
                h1 = h1->next;
            }else{
                curr->next = h2;
                h2 = h2->next;
            }
            curr = curr->next;
        }
        if(h1) curr->next = h1;
        if(h2) curr->next = h2;
        return dummy->next;
    }

    ListNode* mergeSort (ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast = head->next, * slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h1 = head, * h2 = slow->next;
        slow->next = NULL; 
        h1 = mergeSort(h1);
        h2 = mergeSort(h2);
        return merge(h1, h2);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};