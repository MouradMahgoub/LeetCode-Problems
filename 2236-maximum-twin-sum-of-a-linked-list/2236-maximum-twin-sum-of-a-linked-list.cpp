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
    ListNode* reverseList (ListNode* head) {
        ListNode * curr = head, * prev = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* tail = reverseList(slow);
        int ans = -1e9;
        while(tail){
            ans = max(ans, head->val + tail->val);
            head = head->next;
            tail = tail->next;
        }
        return ans;
    }
};
        // ListNode* temp = head;
        // int n = 0;
        // while(temp){
        //     n++;
        //     temp = temp->next;
        // }
        // vector<int> v(n/2, 0);
        // temp = head;
        // for(int i=0; i<n/2; i++){
        //     v[i] = temp->val;
        //     temp = temp->next;
        // }
        // for(int i=n/2 - 1; i>=0; i--){
        //     v[i] += temp->val;
        //     temp = temp->next;
        // }
        // int ans = -1e9;
        // for(int num : v) ans = max(ans, num);
        // return ans;