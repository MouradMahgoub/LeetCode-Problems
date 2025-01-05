class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        Node () {}
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
};

class LRUCache {

private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* dummyHead;
    Node* dummyTail;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        dummyHead = new Node();
        dummyTail = new Node();
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        makeRecently(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        Node* node;
        if(mp.find(key) == mp.end()){
            node = new Node(key, value);
            addLast(node);
            mp[key] = node;
        } else {
            node = mp[key];
            node->val = value;
            makeRecently(node);
        }
        
        if(mp.size() > capacity) {
            mp.erase(dummyHead->next->key);
            removeLRU();
        }
    }

    void addLast (Node* node) {
        node->next = dummyTail;
        node->prev = dummyTail->prev;
        dummyTail->prev->next = node;
        dummyTail->prev = node;
    }

    void makeRecently (Node* node) {
        removeNode(node);
        addLast(node);
    }

    void removeNode (Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void removeLRU () {
        removeNode (dummyHead->next);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */