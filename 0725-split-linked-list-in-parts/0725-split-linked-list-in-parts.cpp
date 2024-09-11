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

    int getLen (ListNode* head) {
        if(!head) return 0;
        return 1 + getLen(head->next);
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getLen(head);
        int partLen = len/k;
        int overLen = len%k;
        vector<ListNode*> ans;
        while(k--){
            int totalLen = partLen+(overLen > 0);
            ans.push_back(head);
            for(int i=0; i<totalLen-1; i++){
                head = head->next;
            }
            if(totalLen > 0) {
                ListNode* temp = head->next;
                head->next = NULL;
                head = temp;
            }
            overLen--;
        }
        return ans;
    }
};