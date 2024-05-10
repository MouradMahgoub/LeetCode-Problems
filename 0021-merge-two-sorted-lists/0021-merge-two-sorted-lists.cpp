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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                dummy->next = list1;
                list1 = list1->next;
            }else{
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        dummy->next = list1 ? list1 : list2;
        return head->next;
    }
};