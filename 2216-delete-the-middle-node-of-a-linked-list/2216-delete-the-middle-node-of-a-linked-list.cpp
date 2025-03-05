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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        auto slow = head, fast = head->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
        // if(!head->next) return NULL;
        // ListNode* temp = head;
        // int len = 0;
        // while(temp){
        //     len++;
        //     temp = temp->next;
        // }
        // temp = head;
        // for(int i=0; i<len/2 - 1; i++) temp = temp->next;
        // temp->next = temp->next->next;
        // return head;