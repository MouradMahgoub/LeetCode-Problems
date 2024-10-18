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
    private ListNode reverse (ListNode start, ListNode end) {
        ListNode nextEnd = end.next;
        ListNode prev = nextEnd, curr = start;
        while(curr != nextEnd){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode prevGroup = dummy, start = head, end = head;
        int cnt = 0;
        while(end != null){
            if(++cnt%k != 0){
                end = end.next;
            }else{
                reverse(start, end);
                prevGroup.next = end;
                prevGroup = start;
                start = start.next;
                end = start;
            }
        }
        return dummy.next;
    }
}