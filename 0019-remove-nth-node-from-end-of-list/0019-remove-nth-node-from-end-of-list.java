/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverse (ListNode head) {
        ListNode prev = null, curr = head;
        while(curr != null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public ListNode removeNthNode (ListNode head, int n) {
        if(n == 1) return head.next;
        ListNode curr = head;
        for(int i=0; i<n-2; i++) curr = curr.next;
        curr.next = curr.next.next;
        return head;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        head = reverse(head);
        head = removeNthNode(head, n);
        head = reverse(head);
        return head;
    }
}