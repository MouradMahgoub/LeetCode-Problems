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
    private ListNode partition (ListNode[] lists, int l, int r) {
        if(l > r) return null;
        if(l == r) return lists[l];
        int mid = l + (r - l)/2;
        ListNode leftPart = partition (lists, l, mid);
        ListNode rightPart = partition (lists, mid+1, r);
        return merge(leftPart, rightPart);
    }
    
    private ListNode merge (ListNode n1, ListNode n2) {
        ListNode dummy = new ListNode();
        ListNode p1 = n1, p2 = n2, curr = dummy;
        while(p1 != null && p2 != null){
            if(p1.val < p2.val){
                curr.next = p1;
                p1 = p1.next;
            }else{
                curr.next = p2;
                p2 = p2.next;
            }
            curr = curr.next;
        }
        if(p1 != null) curr.next = p1;
        if(p2 != null) curr.next = p2;
        return dummy.next;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        return partition(lists, 0, lists.length-1);
    }
}