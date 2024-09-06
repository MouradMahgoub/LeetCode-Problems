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
    unordered_map<int, int> mp;

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for(int num : nums) mp[num]++;
        while(head && mp[head->val]) head = head->next;
        if(!head) return NULL;
        ListNode* curr = head;
        while(curr->next){
            if(mp[curr->next->val]) {
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            } 
        }
        return head;
    }
};