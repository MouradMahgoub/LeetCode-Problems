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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int mxNode = INT_MIN;
    ListNode* removeNodes(ListNode* head) {
        ListNode* lastNode = reverseList(head);
        ListNode* curr = lastNode;
        while(curr->next != NULL){
            if(curr->val > curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return reverseList(lastNode);
    }
};
        // if(head == NULL) return head;
        // removeNodes(head->next);
        // mxNode = max(mxNode, head->val);
        // if(mxNode > head->val){
        //     head->val = mxNode;
        //     head->next = head->next->next;
        // }