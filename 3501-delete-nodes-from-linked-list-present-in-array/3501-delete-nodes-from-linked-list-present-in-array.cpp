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
        while(mp[head->val]) head = head->next;
        ListNode* prev = head, * curr = head->next;
        while(prev && curr){
            if(mp[curr->val]) {
                prev->next = curr->next;
            }else{
                prev = curr;
            } 
            curr = curr->next;
        }
        return head;
    }
};