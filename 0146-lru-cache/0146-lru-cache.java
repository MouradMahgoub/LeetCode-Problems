class DNode {
    public int key, val;
    public DNode prev, next;
    public DNode (){}
    public DNode (int k, int v){
        this.key = k;
        this.val = v;
    }
}

class LRUCache { 
    private Map<Integer, DNode> cach = new HashMap<Integer, DNode>(){};
    DNode dummyHead, dummyTail; 
    private int capacity;
    private int len = 0;

    private void addToHead (DNode node) {
        cach.put(node.key, node);
        node.prev = dummyHead;
        node.next = dummyHead.next;
        dummyHead.next.prev = node;
        dummyHead.next = node;
    }

    private void moveToHead (DNode node) {
        removeNode(node);
        addToHead(node);
    }

    private void removeNode (DNode node) {
        cach.remove(node.key);
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.dummyHead = new DNode();
        this.dummyTail = new DNode();
        dummyHead.next = dummyTail;
        dummyTail.prev = dummyHead;
    }
    
    public int get(int key) {
        DNode node = cach.get(key);
        if(node == null)
            return -1;
        moveToHead(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        DNode node = cach.get(key);
        if(node != null){
            node.val = value;
            moveToHead(node);
            return;
        }
        node = new DNode(key, value);
        addToHead(node);
        len++;
        if(len > capacity){
            removeNode(dummyTail.prev);
            len--;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */