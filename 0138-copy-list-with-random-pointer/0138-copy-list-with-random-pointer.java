/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        Node copyHead = new Node(head.val);
        Node temp = head, copyTemp = copyHead;
        HashMap<Node, Node> mp = new HashMap<>();
        mp.put(null, null);
        while(temp != null){
            mp.put(temp, copyTemp);
            copyTemp.next = (temp.next == null ? null : new Node(temp.next.val));
            temp = temp.next;
            copyTemp = copyTemp.next;
        }
        temp = head; copyTemp = copyHead;
        while(temp != null){
            copyTemp.random = mp.get(temp.random);
            temp = temp.next;
            copyTemp = copyTemp.next;
        }
        return copyHead;
    }
}