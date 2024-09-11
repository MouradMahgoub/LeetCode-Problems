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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        int baseLen = len/k, extraLen = len%k;
        vector<ListNode*> ans;
        ListNode* curr = head;
        for(int i=0; i<k; i++){
            ans.push_back(curr);
            int partLen = baseLen+(extraLen > 0);
            for(int j=0; j<partLen-1; j++){
                curr = curr->next;
            }
            if(curr) {
                ListNode* temp = curr->next;
                curr->next = NULL;
                curr = temp;
            }
            extraLen--;
        }
        return ans;
    }
};