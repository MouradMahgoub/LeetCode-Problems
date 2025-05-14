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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

        // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        // ListNode* dummy = new ListNode();
        // ListNode* head = dummy;
        // while(list1 && list2){
        //     if(list1->val <= list2->val){
        //         dummy->next = list1;
        //         list1 = list1->next;
        //     }else{
        //         dummy->next = list2;
        //         list2 = list2->next;
        //     }
        //     dummy = dummy->next;
        // }
        // dummy->next = list1 ? list1 : list2;
        // return head->next;