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
    ListNode* getMiddle (ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse (ListNode* head) {
        ListNode * prev = NULL, *curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void merge (ListNode* l1, ListNode* l2) {
        while(l1 && l2){
            ListNode* l1Next = l1->next, *l2Next = l2->next;
            l1->next = l2;
            l2->next = l1Next;
            l1 = l1Next;
            l2 = l2Next;
        }
    }

    void reorderList(ListNode* head) {
        ListNode* middleNode = getMiddle(head);
        ListNode* l1 = head, *l2 = middleNode->next;
        middleNode->next = NULL;
        l2 = reverse(l2);
        merge(l1, l2);
        return;
    }
};