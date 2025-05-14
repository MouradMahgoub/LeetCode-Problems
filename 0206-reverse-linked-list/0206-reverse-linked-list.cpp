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
        if(!head) return NULL;
        ListNode* temp = head;
        stack<ListNode*> st;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }

        ListNode* newHead = st.top(); st.pop();
        temp = newHead;
        while(!st.empty()){
            temp->next = st.top(); st.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        return newHead;
    }
};


        // if(!head || !head->next) return head;
        // ListNode* temp = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return temp;


        // if(!head || !head->next) return head;
        // ListNode* newHead = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return newHead;